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
#include "Camera.hpp"
#include <stdio.h>

namespace PGame {
    ExampleScene::ExampleScene() {}
    ExampleScene::ExampleScene (Game *g) : Scene (g) { }
    ExampleScene::ExampleScene (Game *g, int w, int h) : Scene (g, w, h) { }

    void ExampleScene::init (void) {
        // actually get these values from Game
        Camera *camera = new Camera(640, 480);
        this->setCamera(camera);

        Hero *hero = new Hero("example_sprite", "test_img/slug_right.png", this);

        hero->setPos(PVector2D::Vector2D<float>(200.0, 250.0));
        hero->getVelocity()->setY(-1.0f);
        hero->initHitBox(32.0, 32.0);
        //hero->setShowHitBox();

        hero->setTextureForState("test_img/slug_right.png", "non_animated_right");
        hero->setTextureForState("test_img/slug_left.png", "non_animated_left");
        hero->setBodyType("kinematic");

        this->addGameObject(hero);

        SDL_Rect *platformGroundRect = new SDL_Rect();
        platformGroundRect->x = 100;
        platformGroundRect->y = 320;
        platformGroundRect->w = 850;
        platformGroundRect->h = 30;

        SDL_Color *platformGroundColor = new SDL_Color();
        platformGroundColor->r = 0x84;
        platformGroundColor->r = 0x7e;
        platformGroundColor->r = 0x87;
        platformGroundColor->a = 0xff;

        PrimitiveRect *platformGround = new PrimitiveRect("platform0", platformGroundRect, this);
        platformGround->setColor(platformGroundColor);
        platformGround->initHitBox();
        //platformGround->setShowHitBox();
        platformGround->setBodyType("static");

        this->addGameObject(platformGround);

        SDL_Rect *platformCeilRect = new SDL_Rect();
        platformCeilRect->x = 100;
        platformCeilRect->y = 40;
        platformCeilRect->w = 850;
        platformCeilRect->h = 30;

        SDL_Color *platformCeilColor = new SDL_Color();
        platformCeilColor->r = 0x84;
        platformCeilColor->r = 0x7e;
        platformCeilColor->r = 0x87;
        platformCeilColor->a = 0xff;

        PrimitiveRect *platformCeil = new PrimitiveRect("platform0", platformCeilRect, this);
        platformCeil->setColor(platformGroundColor);
        platformCeil->initHitBox();
        //platformCeil->setShowHitBox();
        platformCeil->setBodyType("static");

        this->addGameObject(platformCeil);

        SDL_Rect *platformLeftRect = new SDL_Rect();
        platformLeftRect->x = 100;
        platformLeftRect->y = 70;
        platformLeftRect->w = 30;
        platformLeftRect->h = 250;

        SDL_Color *platformLeftColor = new SDL_Color();
        platformLeftColor->r = 0x84;
        platformLeftColor->r = 0x7e;
        platformLeftColor->r = 0x87;
        platformLeftColor->a = 0xff;

        PrimitiveRect *platformLeft = new PrimitiveRect("platform1", platformLeftRect, this);
        platformLeft->setColor(platformGroundColor);
        platformLeft->initHitBox();
        //platformLeft->setShowHitBox();
        platformLeft->setBodyType("static");

        this->addGameObject(platformLeft);

        SDL_Rect *platformRightRect = new SDL_Rect();
        platformRightRect->x = 920;
        platformRightRect->y = 70;
        platformRightRect->w = 30;
        platformRightRect->h = 250;

        SDL_Color *platformRightColor = new SDL_Color();
        platformRightColor->r = 0x84;
        platformRightColor->r = 0x7e;
        platformRightColor->r = 0x87;
        platformRightColor->a = 0xff;

        PrimitiveRect *platformRight = new PrimitiveRect("platform2", platformRightRect, this);
        platformRight->setColor(platformGroundColor);
        platformRight->initHitBox();
        //platformRight->setShowHitBox();
        platformRight->setBodyType("static");

        this->addGameObject(platformRight);
    }
}
