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
#include <vector>
#include "Sprite.hpp"
#include "GameObject.hpp"
#include "Texture.hpp"
#include "Scene.hpp"
#include "Game.hpp"
#include "Camera.hpp"

namespace PGame {
    class Hero: public Sprite {
    public:
        Hero();
        Hero(std::string);
        Hero(std::string, std::string);
        Hero(std::string, std::string, PGame::Scene*);
        void inputController(const Uint8*);
        void render(void);
        void move(double);
        bool isColliding(std::vector<GameObject*>, std::vector<GameObject>::size_type);
        void resolveCollisions(std::vector<GameObject*>, std::vector<GameObject>::size_type);
        // we might want some enemies to jump too.
        // a descendant of Sprite that allows
        // jumping and _isOnGroundSurface, etc
        // might be a good idea
        bool getIsOnGroundSurface(void);

        bool setTextureForState (std::string, std::string);

    private:
        void updateActiveTexture(void);
        int _initialSpeed = 40;
        int _speed = 20;
        int _maxSpeed = 200;
        int _jumpInitialVelocity = 400;
        bool _isJumping = true;
        bool _isOnGroundSurface = false;
        bool _jumpAvailable = true;

        PTexture::Texture *_non_animated_textures[2] = {NULL, NULL};

        // need a data structure that is a mapping from
        // ANIMATION_STATE/HERO_DIRECTION/HERO_ROTATION combinations
        // to pointers to textures
        typedef enum ANIMATION_STATE {
            IDLE,
            WALK,
            RUN,
            JUMP
        } ANIMATION_STATE;

        typedef enum HERO_DIRECTION {
            LEFT,
            RIGHT

        } HERO_DIRECTION;

        typedef enum HERO_ROTATION {
            ZERO,
            NINETY,
            ONE_EIGHTY,
            TWO_SEVENTY

        } HERO_ROTATION;

        HERO_DIRECTION _hero_direction = RIGHT;
        HERO_ROTATION _hero_rotation = ZERO;

        PTexture::Texture *_active_texture = NULL;
        // add a hash table of animations at some point

    };
}

#endif /* Hero_hpp */
