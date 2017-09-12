//
//  Hero.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/12/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef Hero_hpp
#define Hero_hpp

#include <stdio.h>
#include <string.h>
#include "Sprite.hpp"

#include "GameObject.hpp"
#include "Texture.hpp"
#include "Scene.hpp"
#include "Game.hpp"

namespace PGame {
    class Hero: public Sprite {
    public:
        Hero();
        Hero(std::string);
        Hero(std::string, std::string);
        Hero(std::string, std::string, PGame::Scene);
        void inputController(const Uint8*);

    protected:
        int _initialSpeed = 40;
        int _speed = 20;
        int _maxSpeed = 100;
        // add a hash table of animations at some point

    };
}

#endif /* Hero_hpp */
