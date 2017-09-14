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
    }
}
