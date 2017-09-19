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
    Game *g = new Game("Example Game");

    if (g->init()) {
        //g.loadScene(g.getActiveScene());
        //g.launchActiveSceneInGameLoop();
        // or g.launchActiveSceneGameLoop();
        // if (g.changeScene())...
        // the game should have a GameManager member
        // that deals with changing scenes at the appropriate time,
        // updating UI, etc

        //ExampleScene scene = ExampleScene(&g);
        // next make the texture width and height larger than screen's
        // and start moving the camera to follow Hero
        //ExampleScene scene = ExampleScene(g, g->getScreenWidth(), g->getScreenHeight());
        ExampleScene scene = ExampleScene(g, 1024, 768);
        scene.init();

        g->addScene(&scene);
        g->run();

        //g.destroy();
    }

    return 0;
}
