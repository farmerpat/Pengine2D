//
//  PrimitiveRect.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/14/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "PrimitiveRect.hpp"

namespace PGame {
    PrimitiveRect::PrimitiveRect (void) {
        this->setRenderable();
    }

    PrimitiveRect::PrimitiveRect (std::string name) : GameObject(name) {
        this->setRenderable();
    }

    PrimitiveRect::PrimitiveRect (std::string name, SDL_Rect *r, Scene *s) : GameObject(name, s) {
        this->_rect = r;
        this->setXPos(this->_rect->x);
        this->setYPos(this->_rect->y);

        this->_color = new SDL_Color();
        this->_color->r = 0xff;
        this->_color->g = 0xff;
        this->_color->b = 0xff;
        this->_color->a = 0xff;

        this->setRenderable();
    }

    void PrimitiveRect::setRect (SDL_Rect *r) {
        this->_rect = r;
    }

    void PrimitiveRect::setColor(SDL_Color *c) {
        this->_color = c;
    }

    void PrimitiveRect::render (void) {
        if (this->getParentScene() != NULL) {
            SDL_Renderer *r = this->getParentScene()->getParentGame()->getWindowRenderer();


            if (r != NULL) {
                if (this->_color != NULL) {
                    SDL_SetRenderDrawColor(
                        r,
                        this->_color->r,
                        this->_color->g,
                        this->_color->b,
                        this->_color->a
                    );

                    SDL_RenderFillRect(r, this->_rect);
                }

                if (this->_show_hitbox && this->_hitbox != NULL) {

                    SDL_Color *hbColor = this->getHitBox()->getColor();

                    if (hbColor == NULL) {
                        hbColor = new SDL_Color;
                        hbColor->r = 0x00;
                        hbColor->g = 0x00;
                        hbColor->b = 0x00;
                        hbColor->a = 0xff;
                    }

                    SDL_SetRenderDrawColor(r, hbColor->r, hbColor->g, hbColor->b, hbColor->a);
                    SDL_RenderDrawRect(r, this->getHitBox()->getRect());
                }
            }
        }
    }

    void PrimitiveRect::initHitBox (void) {
        if (this->_rect != NULL) {
            this->_hitbox = new HitBox(this->_rect);

        }
    }

    void PrimitiveRect::setShowHitBox (void) {
        this->_show_hitbox = true;
    }

    void PrimitiveRect::clearShowHitBox (void) {
        this->_show_hitbox = false;

    }

    HitBox *PrimitiveRect::getHitBox (void) {
        return this->_hitbox;

    }
}
