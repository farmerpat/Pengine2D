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
#include "Sprite.hpp"
#include <stdio.h>

namespace PGame {
    ExampleScene::ExampleScene() {}
    // call the parent constructor
    ExampleScene::ExampleScene (Game *g) : Scene (g) { }

    void ExampleScene::init (void) {
        Sprite *s = new Sprite("example_sprite", "test_img/slug_right.png", *this);
        s->setPos(PVector2D::Vector2D<float>(100.0,100.0));

        this->addGameObject(s);

        // make these methods
        //SDL_SetRenderDrawColor(this->_parentGame->getWindowRenderer(), 0xff, 0xff, 0xff, 0xff);
        //SDL_RenderClear(this->_parentGame->getWindowRenderer());

        // make this a method
        //SDL_RenderPresent(this->_parentGame->getWindowRenderer());
    }
}
