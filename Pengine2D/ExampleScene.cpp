//
//  ExampleScene.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/9/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "ExampleScene.hpp"
#include "Texture.hpp"
#include "Game.hpp"
#include "Hero.hpp"
#include "PrimitiveRect.hpp"
#include <stdio.h>

namespace PGame {
    ExampleScene::ExampleScene() {}
    // call the parent constructor
    ExampleScene::ExampleScene (Game *g) : Scene (g) { }

    void ExampleScene::init (void) {
        Hero *hero = new Hero("example_sprite", "test_img/slug_right.png", this);

        hero->setPos(PVector2D::Vector2D<float>(100.0,100.0));
        hero->initHitBox(32.0, 32.0);
        hero->setShowHitBox();

        hero->setTextureForState("test_img/slug_right.png", "non_animated_right");
        hero->setTextureForState("test_img/slug_left.png", "non_animated_left");

        this->addGameObject(hero);

        SDL_Rect *platformRect = new SDL_Rect();
        platformRect->x = 100;
        platformRect->y = 200;
        platformRect->w = 400;
        platformRect->h = 30;

        SDL_Color *platformColor = new SDL_Color();
        platformColor->r = 0x84;
        platformColor->r = 0x7e;
        platformColor->r = 0x87;
        platformColor->a = 0xff;

        PrimitiveRect *platform = new PrimitiveRect("platform0", platformRect, this);
        platform->setColor(platformColor);
        platform->initHitBox();
        platform->setShowHitBox();

        this->addGameObject(platform);
    }
}
