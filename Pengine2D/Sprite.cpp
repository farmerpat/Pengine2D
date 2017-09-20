//
//  Sprite.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/9/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "Sprite.hpp"
#include <stdio.h>

namespace PGame {
    Sprite::Sprite () : GameObject () { }
    Sprite::Sprite (std::string name) : GameObject (name) { }

    Sprite::Sprite (std::string name, std::string pngPath) : GameObject (name) {
        this->_texture_png_path = pngPath;
        if (this->initTexture()) {
            this->setRenderable();
            this->setMovable();

        }
    }

    Sprite::Sprite (std::string name, std::string pngPath, PGame::Scene *parentScene) : GameObject (name, parentScene) {
        this->_texture_png_path = pngPath;
        if (this->initTexture()) {
            this->setRenderable();
            this->setMovable();

        }
    }

    PVector2D::Vector2D<float> *Sprite::getVelocity () {
        return this->_velocity;
    }

    void Sprite::setVelocity (PVector2D::Vector2D<float> newVel) {
        *(this->_velocity) = newVel;
    }

    void Sprite::setGravityDirection (std::string dir) {
        if (dir == "down" || dir == "up" || dir == "left" || dir == "right") {
            this->_gravityDirection = dir;

        }
    }

    std::string Sprite::getGravityDirection (void) {
        return this->_gravityDirection;
    }

    bool Sprite::initTexture () {
        bool success = false;

        if (this->_texture_png_path != "") {
            this->_texture = PTexture::Texture();
            this->_texture.setTargetRenderer(this->getParentScene()->getParentGame()->getWindowRenderer());

            if (this->_texture.loadFromFile(this->_texture_png_path)) {
                success = true;

            }
        }

        return success;
    }

    PTexture::Texture Sprite::getTexture (void) {
        return this->_texture;
    }

    void Sprite::initHitBox (float w, float h) {
        HitBox *hb = new HitBox(this->getPos().getX(), this->getPos().getY(), w, h);

        this->setHitBox(hb);
    }

    void Sprite::render (void) {
        this->_texture.render(this->getPos().getX(), this->getPos().getY());

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

    void Sprite::inputController (const Uint8 *keystates) { }

    void Sprite::move (double dt) {
        float deltaX = this->getVelocity()->getX() * (dt / 1000.0f);
        float newSpriteXPos = this->getPos().getX() + deltaX;
        this->setXPos(newSpriteXPos);

        if (this->hasHitBox()) {
            float newHitBoxXPos = this->getHitBox()->getPos().getX() + deltaX;
            this->getHitBox()->setXPos(newHitBoxXPos);
            this->getHitBox()->updatePosition();
        }

        float deltaY = this->getVelocity()->getY() * (dt / 1000.0f);
        float newSpriteYPos = this->getPos().getY() + deltaY;
        this->setYPos(newSpriteYPos);

        if (this->hasHitBox()) {
            float newHitBoxYPos = this->getHitBox()->getPos().getY() + deltaY;
            this->getHitBox()->setYPos(newHitBoxYPos);
            this->getHitBox()->updatePosition();

        }
    }
}
