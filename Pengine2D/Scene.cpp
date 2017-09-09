//
//  Scene.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "Scene.hpp"

namespace  PScene {
    Scene::Scene () {}

    Scene::~Scene () {
        this->destroy();
    }

    void Scene::addGameObject (PGameObject::GameObject go) {
        this->_gameObjects.push_back(go);
    }

    PGameObject::GameObject *Scene::getGameObjectByName (std::string name) {
        PGameObject::GameObject *go = NULL;

        for (std::vector<PGameObject::GameObject>::size_type i = 0; i < this->_gameObjects.size(); i++) {
            if (this->_gameObjects[i].getName() == name) {
                go = &this->_gameObjects[i];
                break;

            }
        }

        return go;
    }

    void Scene::destroy (void) {

    }
}
