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

namespace PGame {
    ExampleScene::ExampleScene() {}
    // call the parent constructor
    ExampleScene::ExampleScene (Game *g) : Scene (g) { }

    void ExampleScene::init (void) {
        // TODO:
        // this texture should be attached to a game object, which
        // should be attached to the scene
        PTexture::Texture tx = PTexture::Texture();

        tx.setTargetRenderer(this->_parentGame->getWindowRenderer());

        if (tx.loadFromFile("test_img/slug_right.png")) {
            printf("loaded sluggo\n");

            // make these methods
            SDL_SetRenderDrawColor(this->_parentGame->getWindowRenderer(), 0xff, 0xff, 0xff, 0xff);
            SDL_RenderClear(this->_parentGame->getWindowRenderer());

            tx.render(this->_parentGame->getScreenWidth()/2, this->_parentGame->getScreenHeight()/2);

            // make this a method
            SDL_RenderPresent(this->_parentGame->getWindowRenderer());
        } else {
            printf("could not load sluggo: %s\n", IMG_GetError());

        }
    }
}
