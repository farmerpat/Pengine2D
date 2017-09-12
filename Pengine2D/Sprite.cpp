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

    Sprite::Sprite (std::string name, std::string pngPath, PGame::Scene parentScene) : GameObject (name, parentScene) {
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

    void Sprite::render (void) {
        // probably just move the body of renderTexture in here.
        //this->renderTexture();
        this->_texture.render(this->getPos().getX(), this->getPos().getY());
    }

    void Sprite::inputController (const Uint8 *keystates) {
        // this should only be on the player sprite!
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

            this->_velocity->setX(newX);
        } else if (keystates[SDL_SCANCODE_A]) {
            // move left
            newX = this->_velocity->getX() - this->_speed;
            if (newX < -this->_maxSpeed) {
                newX = -this->_maxSpeed;

            }

            this->_velocity->setX(newX);
        }
    }

    void Sprite::move (double dt) {
        float newXPos = this->getVelocity()->getX() * (dt / 1000.0f);
        this->setXPos(this->getPos().getX() + newXPos);

        float newYPos = this->getVelocity()->getY() * (dt / 1000.0f);
        this->setYPos(this->getPos().getY() + newYPos);
    }
}
