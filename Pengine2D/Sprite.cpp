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

        }
    }

    Sprite::Sprite (std::string name, std::string pngPath, PGame::Scene parentScene) : GameObject (name, parentScene) {
        this->_texture_png_path = pngPath;
        if (this->initTexture()) {
            this->setRenderable();
            printf("here we go!");

        }
    }

    PVector2D::Vector2D<int> Sprite::getVelocity () {
        return this->_velocity;
    }

    void Sprite::setVelocity (PVector2D::Vector2D<int> newVel) {
        this->_velocity = newVel;
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

    void Sprite::renderTexture (void) {
        this->_texture.render(this->getPos().getX(), this->getPos().getY());
    }

    PTexture::Texture Sprite::getTexture (void) {
        return this->_texture;
    }

    void Sprite::render (void) {
        // probably just move the body of renderTexture in here.
        this->renderTexture();
    }

    void Sprite::inputController (SDL_Event e) {
        //PVector2D::Vector2D<int> vel = PVector2D::Vector2D<int>();
        // seems like a Movable descendant of a GameObject should exist.
        // Sprite would be a descendent of that
        PVector2D::Vector2D<int> newPos = this->getPos();

        //printf ("das input, <3 Sprite\n");
        switch (e.key.keysym.sym) {
            case SDLK_w:
                // move up
                //vel.setY(-1);
                printf("move up\n");
                newPos.setY(newPos.getY() - this->_speed);
                break;
            case SDLK_a:
                // move left
                //vel.setX(-1);
                printf("move left\n");
                newPos.setX(newPos.getX() - this->_speed);
                break;
            case SDLK_s:
                // move down
                //vel.setY(1);
                printf("move down\n");
                newPos.setY(newPos.getY() + this->_speed);
                break;
            case SDLK_d:
                // move right
                //vel.setX(1);
                printf("move right\n");
                newPos.setX(newPos.getX() + this->_speed);
                break;

        }

        this->setPos(newPos);
    }
}
