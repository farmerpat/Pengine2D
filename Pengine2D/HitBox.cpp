//
//  HitBox.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/14/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "HitBox.hpp"

namespace PGame {
    // GameObject() should be getting called automatically
    HitBox::HitBox (void) {
        // all the SDL_Rect feilds are ints...
        // is sdl even capable of positioning things
        // by float, or should all the gameobject positioning
        // stuff be rewritten for int?
        // if it can position by float, implement our own rect
        SDL_Rect *r = new SDL_Rect();
        r->x = 0;
        r->y = 0;
        r->h = 0;
        r->w = 0;

        this->_rect = r;

        SDL_Color *c = new SDL_Color();
        c->r = 0x76;
        c->g = 0xff;
        c->b = 0x1c;
        c->a = 0xff;

        this->_color = c;
    }

    // call GameObject() explicitly, b/c I don't know which,
    // if any base constructor gets called if there isn't a
    // matching parameter list
    HitBox::HitBox (float xPos, float yPos, int width, int height) : GameObject() {
        SDL_Rect *r = new SDL_Rect();
        r->x = (int)xPos;
        r->y = (int)yPos;
        r->w = width;
        r->h = height;
        this->_rect = r;

        this->setXPos(xPos);
        this->setYPos(yPos);

        SDL_Color *c = new SDL_Color();
        c->r = 0x76;
        c->g = 0xff;
        c->b = 0x1c;
        c->a = 0xff;

        this->_color = c;
    }

    HitBox::HitBox (SDL_Rect *rect) {
        this->_rect = rect;
        this->setXPos(this->_rect->x);
        this->setYPos(this->_rect->y);

        SDL_Color *c = new SDL_Color();
        c->r = 0x76;
        c->g = 0xff;
        c->b = 0x1c;
        c->a = 0xff;

        this->_color = c;
    }

    int HitBox::getWidth (void) {
        int width = 0;

        if (this->_rect != NULL) {
            width = this->_rect->w;
        }

        return width;
    }

    void HitBox::setWidth (int width) {
        if (this->_rect != NULL) {
            this->_rect->w = width;

        }
    }

    int HitBox::getHeight (void) {
        int height = 0;

        if (this->_rect != NULL) {
            height =  this->_rect->h;
        }

        return height;
    }

    void HitBox::setHeight (int height) {
        if (this->_rect != NULL) {
            this->_rect->h = height;

        }
    }

    void HitBox::updatePosition (void) {
        if (this->_rect != NULL) {
            if (this->getPos().getX() != this->_rect->x) {
                this->_rect->x = this->getPos().getX();
            }

            if (this->getPos().getY() != this->_rect->y) {
                this->_rect->y = this->getPos().getY();

            }
        }
    }

    SDL_Rect *HitBox::getRect (void) {
        return this->_rect;
    }

    SDL_Color *HitBox::getColor (void) {
        return this->_color;
    }

    void HitBox::setColor(SDL_Color *c) {
        this->_color = c;
    }

    bool HitBox::isCollidingWith (HitBox *other) {
        bool colliding = true;

        if (this->getRect() == NULL || other->getRect() == NULL) {
            colliding = false;

        } else {
            int myLeft = this->getRect()->x;
            int myRight = myLeft + this->getRect()->w;
            int myTop = this->getRect()->y;
            int myBot = myTop + this->getRect()->h;

            int theirLeft = other->getRect()->x;
            int theirRight = theirLeft + other->getRect()->w;
            int theirTop = other->getRect()->y;
            int theirBot = theirTop + other->getRect()->h;

            if (myBot <= theirTop) {
                colliding = false;

            } else if (myTop >= theirBot) {
                colliding = false;

            } else if (myRight <= theirLeft) {
                colliding = false;

            } else if (myLeft >= theirRight) {
                colliding = false;

            }
        }

        return colliding;
    }

    std::string HitBox::getCollisionLocation (HitBox *other) {
        // if this gets called, the collision can be taken for granted
        std::string collisionLocation = "";
        SDL_Rect *myRect = this->getRect();
        SDL_Rect *theirRect = other->getRect();

        int rightTally = 0;
        int leftTally = 0;
        int topTally = 0;
        int botTally = 0;

        // should these all be floats?
        // we can have float positions,
        // because postion is updated as a function of dt,
        // which is rarely int...
        int myXPos = myRect->x;
        int myYPos = myRect->y;

        int myLeft = myRect->x;
        int myRight = myLeft + myRect->w;
        int myTop = myRect->y;
        int myBot = myTop + myRect->h;

        int theirLeft = theirRect->x;
        int theirRight = theirLeft + theirRect->w;
        int theirTop = theirRect->y;
        int theirBot = theirTop + theirRect->h;

        // check right side
        // ultimately allow specifying width and height plz
        int x = myXPos + 31;
        // if myXPos is also > theirLeft, counting these doesn't make sense
        if (myXPos < theirLeft) {
            for (int y = myYPos; y < (myYPos + 32); y++) {
                // we check each pixel at (x,y)
                // if the pixel is inside other, rightTally++;
                if (x >= theirLeft) {
                    if ((y >= theirTop) && (y <= theirBot)) {
                        rightTally++;

                    }
                }
            }
        }

        // check left side
        // WE GET THE SAME RESULTS, BECAUSE WE ARE IGNORING WHERE MYxpOS+31 IS.
        // IF MYxpOS+31 IS ALSO LESS THAN THEIR RIGHT, COUNTING THESE DOESN'T MAKE ANY SENSE
        x = myXPos;
        if ((myXPos+31) > theirRight) {
            for (int y = myYPos; y < (myYPos + 32); y++) {
                if (x <= theirRight) {
                    if ((y >= theirTop) && (y <= theirBot)) {
                        leftTally++;

                    }
                }
            }
        }

        // check bottom
        int y = myYPos + 31;
        if (myYPos < theirTop) {
            for (int x = myXPos; x < (myXPos + 32); x++) {
                if (y >= theirTop) {
                    if ((x >= theirLeft) && (x <= theirRight)) {
                        botTally++;

                    }
                }
            }
        }

        // check top
        y = myYPos;
        if ((myYPos + 31) > theirBot) {
            for (int x = myXPos; x < (myXPos + 32); x++) {
                if (y <= theirBot) {
                    if ((x >= theirLeft) && (x <= theirRight)) {
                        topTally++;

                    }
                }
            }
        }

        struct CollisionTally {
            int count;
            std::string name;
            CollisionTally(int c, std::string n) : count(c), name(n) { }
        };

        struct greater_than_tally {
            inline bool operator() (const CollisionTally &s1, const CollisionTally &s2) {
                return s1.count > s2.count;

            }
        };

        std::vector <CollisionTally> tallies;
        tallies.push_back(CollisionTally(rightTally, "right"));
        tallies.push_back(CollisionTally(leftTally, "left"));
        tallies.push_back(CollisionTally(botTally, "bot"));
        tallies.push_back(CollisionTally(topTally, "top"));
        std::sort(tallies.begin(), tallies.end(), greater_than_tally());

        if (tallies[0].name == "right") {
            collisionLocation = "right";
            if (tallies[1].count == tallies[0].count) {
                if (tallies[1].name == "top") {
                    collisionLocation = "topright";

                } else if (tallies[1].name == "bot") {
                    collisionLocation = "botright";

                }
            }
        } else if (tallies[0].name == "left") {
            collisionLocation = "left";
            if (tallies[1].count == tallies[0].count) {
                if (tallies[1].name == "top") {
                    collisionLocation = "topleft";

                } else if (tallies[1].name == "bot") {
                    collisionLocation = "botleft";

                }
            }
        } else if (tallies[0].name == "bot") {
            collisionLocation = "bot";
            if (tallies[1].count == tallies[0].count) {
                if (tallies[1].name == "right") {
                    collisionLocation = "botright";

                } else if (tallies[1].name == "left") {
                    collisionLocation = "botleft";

                }
            }
        } else if (tallies[0].name == "top") {
            collisionLocation = "top";

            if (tallies[1].count == tallies[0].count) {
                if (tallies[1].name == "right") {
                    collisionLocation = "topright";

                } else if (tallies[1].name == "left") {
                    collisionLocation = "topleft";

                }
            }
        }

        return collisionLocation;
    }
}
