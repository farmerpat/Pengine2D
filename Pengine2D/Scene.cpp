//
//  Scene.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "Scene.hpp"
#include "Game.hpp"

namespace  PGame {
    Scene::Scene () {}

    Scene::Scene (Game *g) {
        this->_parentGame = g;
    }

    Scene::Scene (Game *g, int w, int h) {
        this->_parentGame = g;
        this->_sceneTexture = SDL_CreateTexture(
            this->_parentGame->getWindowRenderer(),
            // NOTE: this will change depending on endianness of machine. might break on different boxes
            SDL_PIXELFORMAT_RGBA32,
            SDL_TEXTUREACCESS_TARGET,
            w,
            h

        );

        // we could really init the camera in here
    }

    Scene::~Scene () {
        this->destroy();
    }

    void Scene::addGameObject (GameObject *go) {
        this->_gameObjects.push_back(go);
    }

    Game *Scene::getParentGame (void) {
        return this->_parentGame;
    }

    GameObject *Scene::getGameObjectByName (std::string name) {
        GameObject *go = NULL;

        for (std::vector<GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            if (this->_gameObjects[i]->getName() == name) {
                go = this->_gameObjects[i];
                break;

            }
        }

        return go;
    }

    void Scene::inputController (const Uint8 *keystates) {
        for (std::vector<GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            this->_gameObjects[i]->inputController(keystates);

        }
    }

    void Scene::render (void) {
        // allow a bg color
        //SDL_SetRenderDrawColor(this->_parentGame->getWindowRenderer(), 0xa5, 0xc7, 0xff, 0xff);
        //SDL_RenderClear(this->_parentGame->getWindowRenderer());

        /*
         // you would think this belongs here,
         // but im not sure that it does...
        SDL_Rect *previousCamViewPort = new SDL_Rect();
        SDL_RenderGetClipRect(renderer, previousCamViewPort);

        SDL_RenderSetClipRect(renderer, cam->getViewPort());

         i think the windowRenderer will be the same size as the camera,
         but the Scene renderer will be the size of the level then...

        // clip is rect selection from _sceneTexture
        // clip is camera
         // renderQuad is null...or camera... idk
         // if its null the texture is stretched to fill the whole thing...
        // renderQuad is rect destination on _windowRenderer
        SDL_RenderCopy(this->_windowRenderer, this->_sceneTexture, clip, &renderQuad);
         //
         // I THINK A SCENE NEEDS TO HAVE ITS OWN TEXTURE, WHICH IS THE SIZE OF THE LEVEL..
         */

        // change all the GameObject renderer functions to get the parent scenes _sceneTexture
        // and render to that shit
        SDL_SetRenderTarget(this->_parentGame->getWindowRenderer(), this->_sceneTexture);
        SDL_SetRenderDrawColor(this->_parentGame->getWindowRenderer(), 0xa5, 0xc7, 0xff, 0xff);
        SDL_RenderClear(this->_parentGame->getWindowRenderer());

        for (std::vector<GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            if (this->_gameObjects[i]->isRenderable()) {
                //this->_gameObjects[i]->render(NULL);
                this->_gameObjects[i]->render(this->getCamera());

            }
        }

        // do the thing with the camera clip noted above
        // then
        SDL_SetRenderTarget(this->_parentGame->getWindowRenderer(), NULL);

        SDL_RenderCopy(
            this->_parentGame->getWindowRenderer(),
            this->_sceneTexture,
            this->_camera->getViewPort(),
            this->_camera->getViewPort() // NULL?
        );

        SDL_RenderPresent(this->_parentGame->getWindowRenderer());
    }

    void Scene::move (double dt) {
        for (std::vector<GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            if (this->_gameObjects[i]->isMovable()) {
                this->_gameObjects[i]->move(dt);

            }
        }
    }

    void Scene::resolveCollisions (void) {
        for (std::vector<GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            if (this->_gameObjects[i]->getBodyType() == "kinematic") {
                if (this->_gameObjects[i]->isColliding(this->_gameObjects, i)) {
                    this->_gameObjects[i]->resolveCollisions(this->_gameObjects, i);

                }
            }
        }
    }

    void Scene::applyDragAndGravity (double dt) {
        float xTolerance = 0.01f;
        float xDrag = 0.20f;
        // for testing for now.  downward drag only in game probably.
        // the amount of drag applied will depend on whether or not jump is held
        float yDrag = 0.20f;
        float yTolerance = 0.01f;

        // if there's no button being pressed, apply drag to the player,
        // so he eventually stops
        // need a Player:Sprite class...
        // OR JUST CHECK THE TAG
        for (std::vector<GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            if (this->_gameObjects[i]->isMovable()) {
                PVector2D::Vector2D<float> *vel = this->_gameObjects[i]->getVelocity();
                float xVel = vel->getX();
                float yVel = vel->getY();

                if (xVel > 0) {
                    // moving right
                    if (xVel < xTolerance) {
                        xVel = 0.0f;

                    } else if (xVel - (xDrag * dt) < 0) {
                        xVel = 0.0f;

                    } else {
                        xVel -= (xDrag * dt);

                    }
                } else if (xVel < 0) {
                    // moving left
                    if (xVel > -xTolerance) {
                        xVel = 0.0f;

                    } else if (xVel + (xDrag * dt) > 0) {
                        xVel = 0.0f;

                    } else {
                        xVel += (xDrag * dt);

                    }
                }

                this->_gameObjects[i]->getVelocity()->setX(xVel);

                if (yVel > 0) {
                    if (yVel < yTolerance) {
                        yVel = 0.0f;
                    } else if (yVel - (yDrag * dt) < 0) {
                        yVel = 0.0f;

                    } else {
                        yVel -= (yDrag * dt);

                    }
                } else if (yVel < 0) {
                    if (yVel > -yTolerance) {
                        yVel = 0.0f;

                    } else if (yVel + (yDrag * dt) > 0) {
                        yVel = 0.0f;

                    } else {
                        yVel += (yDrag * dt);

                    }
                }

                this->_gameObjects[i]->getVelocity()->setY(yVel);
                // apply gravity to y if velocity is negative
                // this only makes sense to do when there is
                // something to collide with under the player

            }
        }
    }

    void Scene::setCamera (Camera *c) {
        this->_camera = c;
    }

    Camera *Scene::getCamera (void) {
        return this->_camera;
    }

    // take w and h of game target too!
    void Scene::centerCameraAround (int x, int y) {
        PVector2D::Vector2D<float> newCameraPos = PVector2D::Vector2D<float>();
        int texW;
        int texH;
        SDL_QueryTexture(this->_sceneTexture, NULL, NULL, &texW, &texH);
        // ADD SANITY CHECK for texW and texH
        //int camMaxX = this->getParentGame()->getScreenWidth() - this->getCamera()->getViewPort()->w;
        int camMaxX = texW - this->getCamera()->getViewPort()->w;

        int camMinX = 0;
        //int camMaxY = this->getParentGame()->getScreenHeight() - this->getCamera()->getViewPort()->h;
        int camMaxY = texH - this->getCamera()->getViewPort()->h;
        int camMinY = 0;
        int newCamX = x - (this->getCamera()->getViewPortWidth() / 2);
        int newCamY = y -(this->getCamera()->getViewPortHeight() / 2);
        //int newCamX = (this->getCamera()->getViewPortWidth() / 2) - x;
        //int newCamY = (this->getCamera()->getViewPortHeight() / 2) - y;

        if (newCamX < camMinX) {
            newCamX = camMinX;

        } else if (newCamX > camMaxX) {
            newCamX = camMaxX;

        }

        if (newCamY < camMinY) {
            newCamY = camMinY;

        } else if (newCamY > camMaxY) {
            newCamY = camMaxY;

        }

        newCameraPos.setX((float)newCamX);
        newCameraPos.setY((float)newCamY);

        this->getCamera()->setPos(newCameraPos);
        this->getCamera()->updatePos();
    }

    void Scene::moveCamera (int x, int y) {
        PVector2D::Vector2D<float> newCameraPos = PVector2D::Vector2D<float>();
        int camMaxX = this->getParentGame()->getScreenWidth() - this->getCamera()->getViewPort()->w;
        int camMinX = 0;
        int camMaxY = this->getParentGame()->getScreenHeight() - this->getCamera()->getViewPort()->h;
        int camMinY = 0;

        if (x < camMinX) {
            x = camMinX;

        } else if (x > camMaxX) {
            x = camMaxX;

        }

        if (y < camMinY) {
            y = camMinY;

        } else if (y > camMaxY) {
            y = camMaxY;

        }

        newCameraPos.setX((float)x);
        newCameraPos.setY((float)y);

        this->getCamera()->setPos(newCameraPos);
        this->getCamera()->updatePos();
    }

    void Scene::destroy (void) {

    }
}
