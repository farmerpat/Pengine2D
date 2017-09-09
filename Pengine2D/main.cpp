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
#include "ExampleScene.hpp"

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
        // or g.launchActiveSceneGameLoop();
        // if (g.changeScene())...
        // the game should have a GameManager member
        // that deals with changing scenes at the appropriate time,
        // updating UI, etc

        PGame::ExampleScene scene = PGame::ExampleScene(&g);
        scene.init();

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

    // g.cleanUp();
    return 0;
}
