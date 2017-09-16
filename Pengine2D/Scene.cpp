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
        SDL_SetRenderDrawColor(this->_parentGame->getWindowRenderer(), 0xa5, 0xc7, 0xff, 0xff);
        SDL_RenderClear(this->_parentGame->getWindowRenderer());

        for (std::vector<GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            if (this->_gameObjects[i]->isRenderable()) {
                this->_gameObjects[i]->render();

            }
        }

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
                    printf("das collision\n");
                    this->_gameObjects[i]->resolveCollisions(this->_gameObjects, i);

                }
            }
        }
    }

    void Scene::applyDragAndGravity (double dt) {
        float xTolerance = 0.01f;
        float xDrag = 0.20f;

        // if there's no button being pressed, apply drag to the player,
        // so he eventually stops
        // need a Player:Sprite class...
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
                // apply gravity to y if velocity is negative
                // this only makes sense to do when there is
                // something to collide with under the player

            }
        }
    }

    void Scene::destroy (void) {

    }
}
