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
        PVector2D::Vector2D<int> getVelocity();
        void setVelocity(PVector2D::Vector2D<int>);
        void inputController(SDL_Event);
        bool initTexture(void);
        PTexture::Texture getTexture(void);
        void renderTexture(void);
        void render(void);

    private:
        PVector2D::Vector2D<int> _velocity = PVector2D::Vector2D<int>(0,0);
        std::string _texture_png_path = "";
        PTexture::Texture _texture;
        int _speed = 2;
        // add a hash table of animations at some point

    };
}
#endif /* Sprite_hpp */
