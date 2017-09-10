//
//  GameObject.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "GameObject.hpp"

namespace  PGame {
    GameObject::GameObject () {
        this->_int_position = PVector2D::Vector2D<int>(0,0);
    }

    GameObject::GameObject (std::string name) {
        this->_int_position = PVector2D::Vector2D<int>(0,0);
        this->_name = name;
    }

    GameObject::GameObject (std::string name, PGame::Scene scene) {
        this->_int_position = PVector2D::Vector2D<int>(0,0);
        this->_name = name;
        this->_parentScene = &scene;
    }

    std::string GameObject::getTag () {
        return this->_tag;
    }

    void GameObject::setTag(std::string newTag) {
        this->_tag = newTag;
    }

    std::string GameObject::getName (void) {
        return this->_name;
    }

    void GameObject::setName (std::string newName) {
        this->_name = newName;
    }

    PVector2D::Vector2D<int> GameObject::getPos () {
        return this->_int_position;
    }

    void GameObject::setPos (PVector2D::Vector2D<int> newVec) {
        this->_int_position = newVec;
    }

    void GameObject::setXPos (int x) {
        this->_int_position.setX(x);
        //if (typeid(x).name == typeid(this->_position.getX()).name) {
        //    this->_position->setXPos(x);
        //}

        // otherwise, throw an error or something useful
    }

    //void GameObject::setXPos (float x) {

    //}

    void GameObject::setYPos (int y) {
        this->_int_position.setY(y);
    }

    //void GameObject::setYPos (float y) {

    //}

    PGame::Scene *GameObject::getParentScene (void) {
        return this->_parentScene;
    }

    GameObject::~GameObject () {}
}
