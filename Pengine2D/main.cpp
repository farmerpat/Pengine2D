//
//  main.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Vector2D.hpp"
#include "Texture.hpp"
#include "GameObject.hpp"
#include "Game.hpp"

using namespace PGame;

int main(int argc, const char * argv[]) {
    bool quit = false;
    printf("quit: %d\n", quit);

    PGameObject::GameObject go = PGameObject::GameObject();
    go.setTag("player");
    go.setXPos(30);
    go.setYPos(43);

    printf("tag: %s\n", go.getTag().c_str());
    printf("xpos: %d\n", go.getPos().getX());
    printf("ypos: %d\n", go.getPos().getY());

    Game g = Game("dis test");
    printf("title: %s\n", g.getTitle().c_str());

    if (g.init()) {
        //g.loadScene(g.getActiveScene());
        //g.launchActiveSceneInGameLoop();
        // or g.launchGameLoop();
        // the game should have a GameManager member
        // that deals with changing scenes at the appropriate time,
        // updating UI, etc

        PTexture::Texture tx = PTexture::Texture();
        tx.setTargetRenderer(g.getWindowRenderer());

        if (tx.loadFromFile("test_img/slug_right.png")) {
            printf("loaded sluggo\n");

            // make these methods
            SDL_SetRenderDrawColor(g.getWindowRenderer(), 0xff, 0xff, 0xff, 0xff);
            SDL_RenderClear(g.getWindowRenderer());

            tx.render(g.getScreenWidth()/2, g.getScreenHeight()/2);

            // make this a method
            SDL_RenderPresent(g.getWindowRenderer());
        } else {
            printf("could not load sluggo\n");

        }

        SDL_Delay(10000);
        g.destroy();
    }

    /*
    // init();
    // loadMedia();

    while (! quit) {
        // get input
        // update camera, sprite positions, UI, trigger sounds,
        // redraw screen

    }
     */

    // cleanUp();
    return 0;
}
