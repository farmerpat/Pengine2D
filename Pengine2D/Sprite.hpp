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
#include "HitBox.hpp"
#include "Game.hpp"

namespace PGame {
    class Sprite: public GameObject {
    public:
        Sprite();
        Sprite(std::string);
        Sprite(std::string, std::string);
        Sprite(std::string, std::string, PGame::Scene*);

        PVector2D::Vector2D<float> *getVelocity();

        bool hasHitBox(void);
        void initHitBox (float, float);
        void setShowHitBox(void);
        void clearShowHitBox(void);

        void setVelocity(PVector2D::Vector2D<float>);
        virtual void inputController(const Uint8*);
        void move(double);
        bool initTexture(void);
        PTexture::Texture getTexture(void);
        void render(void);

    protected:
        PVector2D::Vector2D<float> *_velocity = new PVector2D::Vector2D<float>(0.0,0.0);
        std::string _texture_png_path = "";
        PTexture::Texture _texture;
        bool _show_hitbox = false;

    };
}
#endif /* Sprite_hpp */
