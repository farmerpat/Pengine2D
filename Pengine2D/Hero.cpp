//
//  Hero.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/12/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "Hero.hpp"
//#include <stdio.h>

namespace PGame {
    Hero::Hero() { }
    Hero::Hero (std::string name) : Sprite (name) { }
    Hero::Hero (std::string name, std::string pngPath) : Sprite (name, pngPath) {
        this->_active_texture = &this->_texture;
    }

    Hero::Hero (std::string name, std::string pngPath, PGame::Scene *parentScene) : Sprite (name, pngPath, parentScene) {
        this->_active_texture = &this->_texture;
    }

    bool Hero::setTextureForState (std::string path, std::string state) {
        bool success = true;

        PTexture::Texture *t = new PTexture::Texture();
        // this->getParentScene()->getParentGame()->getWindowRenderer() should be a class member
        // set in the conststructor
        t->setTargetRenderer(this->getParentScene()->getParentGame()->getWindowRenderer());
        success = t->loadFromFile(path);

        if (success) {
            if (state == "non_animated_left") {
                this->_non_animated_textures[LEFT] = t;

            } else if (state == "non_animated_right") {
                this->_non_animated_textures[RIGHT] = t;

            }
        }

        return success;
    }

    void Hero::inputController (const Uint8 *keystates) {
        // maybe seems like a Movable descendant of a GameObject should exist.
        // Sprite would be a descendent of that
        float newX = 0.0;
        float newY = 0.0;

        if (keystates[SDL_SCANCODE_W]) {
            // move up
            newY = this->_velocity->getY() - this->_speed;
            if (newY < -this->_maxSpeed) {
                newY = -this->_maxSpeed;

            }

            this->_velocity->setY(newY);
        }

        if (keystates[SDL_SCANCODE_D]) {
            // move right
            newX = this->_velocity->getX() + this->_speed;
            if (newX > this->_maxSpeed) {
                newX = this->_maxSpeed;
            }

            this->_hero_direction = RIGHT;
            this->_velocity->setX(newX);
        } else if (keystates[SDL_SCANCODE_A]) {
            // move left
            newX = this->_velocity->getX() - this->_speed;
            if (newX < -this->_maxSpeed) {
                newX = -this->_maxSpeed;

            }

            this->_hero_direction = LEFT;
            this->_velocity->setX(newX);
        }
    }

    void Hero::updateActiveTexture (void) {
        // update for animation eventually...
        if (this->_hero_direction == LEFT) {
            if (this->_non_animated_textures[LEFT] != NULL) {
                this->_active_texture = this->_non_animated_textures[LEFT];

            }
        } else if (this->_hero_direction == RIGHT) {
            if (this->_non_animated_textures[RIGHT] != NULL) {
                this->_active_texture = this->_non_animated_textures[RIGHT];

            }
        }
    }

    bool Hero::isColliding(std::vector<GameObject*> gos, std::vector<GameObject>::size_type i) {
        bool colliding = false;

        for (std::vector<GameObject>::size_type j = 0; j < gos.size(); j++) {
            if (j == i) {
                continue;

            } else {
                if (gos[j]->getBodyType() == "kinematic" || gos[j]->getBodyType() == "static") {
                    if (this->getHitBox()->isCollidingWith(gos[j]->getHitBox())) {
                        colliding = true;
                        break;

                    }
                }
            }
        }

        return colliding;
    }

    // can probably avoid calling isColliding b/c we could just
    // call resolveCollisions instead.  it wouldn't do anything if
    // there weren't any collisions to resolve
    void Hero::resolveCollisions (std::vector<GameObject*> gos, std::vector<GameObject>::size_type i) {
        std::vector<GameObject*> collidingOthers = std::vector<GameObject*>();

        for (std::vector<GameObject>::size_type j = 0; j < gos.size(); j++) {
            if (j == i) {
                continue;

            } else {
                if (gos[j]->getBodyType() == "kinematic" || gos[j]->getBodyType() == "static") {
                    if (this->getHitBox()->isCollidingWith(gos[j]->getHitBox())) {
                        collidingOthers.push_back(gos[j]);

                    }
                }
            }
        }

        if (collidingOthers.size() > 0) {
            // instead of pushing and interating again, its faster
            // to just resolve the collision in the loop above.
            // this probably makes debugging easier tho
            for (std::vector<GameObject>::size_type j = 0; j < collidingOthers.size(); j++) {
                // we know Hero's velocity, and the vecocity in each of collidingOthers.
                // finding the normal and sliding where applicable and so forth
                // probably makes sense ultimately.
                // for now, there is only one use case.. Hero coming in from the left.
                // change is x velocity and stfu for now
                HitBox *myHitBox = this->getHitBox();
                HitBox *theirHitBox = collidingOthers[j]->getHitBox();

                std::string collisionLocation = myHitBox->getCollisionLocation(theirHitBox);

                if (collisionLocation == "myRightTheirLeft") {
                    printf("myRightTheirLeft\n");

                } else if (collisionLocation == "myLeftTheirRight") {
                    printf("myLeftTheirRight\n");

                } else if (collisionLocation == "myTopTheirBottom") {
                    printf("myTopTheirBottom\n");

                } else if (collisionLocation == "myBottomTheirTop") {
                    printf("myBottomTheirTop\n");

                } else if (collisionLocation == "myTopRightCornerTheirBottomLeftCorner") {
                    printf("myTopRightCornerTheirBottomLeftCorner\n");

                } else if (collisionLocation == "myBottomRightCornerTheirTopLeftCorner") {
                    printf("myBottomRightCornerTheirTopLeftCorner\n");

                } else if (collisionLocation == "myTopLeftCornerTheirBottomRightCorner") {
                    printf("myTopLeftCornerTheirBottomRightCorner\n");

                } else if (collisionLocation == "myBottomLeftCornerTheirTopRightCorner") {
                    printf("myBottomLeftCornerTheirTopRightCorner\n");

                } else {
                    printf ("unrecognized collision. derp\n");

                }



                PVector2D::Vector2D<float> *currentVel = this->getVelocity();

                // consider locking player movement along axes for when
                // we latch onto a wall or surface
                // it can only be relased by jump btn
                // and only enaged with lock btn, excluding normal ground
                // try set pos away from it first...
                // doing this requires that we update the hitbox position too though...
                PVector2D::Vector2D<float> pos = this->getPos();
                pos.setX(pos.getX() - 1.0);
                //this->setPos(pos);
                currentVel->setX(-50.0);
                //currentVel->setX(0);

            }
        }
    }

    void Hero::render (void) {
        this->updateActiveTexture();

        if (this->_active_texture != NULL) {
            this->_active_texture->render(this->getPos().getX(), this->getPos().getY());
        }

        if (this->getShowHitBox() && this->getHitBox() != NULL) {
            SDL_Renderer *renderer = this->getTexture().getTargetRenderer();

            if (renderer != NULL) {
                SDL_Color *hbColor = this->getHitBox()->getColor();

                if (hbColor == NULL) {
                    hbColor = new SDL_Color;
                    hbColor->r = 0x00;
                    hbColor->g = 0x00;
                    hbColor->b = 0x00;
                    hbColor->a = 0xff;
                }

                SDL_SetRenderDrawColor(renderer, hbColor->r, hbColor->g, hbColor->b, hbColor->a);
                SDL_RenderDrawRect(renderer, this->getHitBox()->getRect());
            }
        }
    }

    void Hero::move (double dt) {
        Sprite::move(dt);

    }
}
