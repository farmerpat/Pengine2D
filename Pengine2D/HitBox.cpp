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
}
