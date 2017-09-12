//
//  Sprite.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/9/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <stdio.h>
#include <string>
#include "GameObject.hpp"
#include "Texture.hpp"
#include "Scene.hpp"
#include "Game.hpp"

namespace PGame {
    class Sprite: public GameObject {
    public:
        Sprite();
        Sprite(std::string);
        Sprite(std::string, std::string);
        Sprite(std::string, std::string, PGame::Scene);
        PVector2D::Vector2D<float> *getVelocity();
        void setVelocity(PVector2D::Vector2D<float>);
        void inputController(const Uint8*);
        void move(double);
        bool initTexture(void);
        PTexture::Texture getTexture(void);
        void render(void);

    private:
        PVector2D::Vector2D<float> *_velocity = new PVector2D::Vector2D<float>(0.0,0.0);
        std::string _texture_png_path = "";
        PTexture::Texture _texture;
        int _initialSpeed = 40;
        int _speed = 20;
        int _maxSpeed = 100;
        // add a hash table of animations at some point

    };
}
#endif /* Sprite_hpp */
