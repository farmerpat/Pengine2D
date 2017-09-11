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

    void Scene::inputController (SDL_Event e) {
        for (std::vector<GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            this->_gameObjects[i]->inputController(e);

        }
    }

    void Scene::render (void) {
        // allow a bg color
        SDL_SetRenderDrawColor(this->_parentGame->getWindowRenderer(), 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(this->_parentGame->getWindowRenderer());

        for (std::vector<GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            if (this->_gameObjects[i]->isRenderable()) {
                this->_gameObjects[i]->render();

            }
        }

        SDL_RenderPresent(this->_parentGame->getWindowRenderer());
    }

    void Scene::destroy (void) {

    }
}
