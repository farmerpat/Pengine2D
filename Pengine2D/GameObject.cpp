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
        this->_position = PVector2D::Vector2D<float>(0.0,0.0);
    }

    GameObject::GameObject (std::string name) {
        this->_position = PVector2D::Vector2D<float>(0.0,0.0);
        this->_name = name;
    }

    GameObject::GameObject (std::string name, PGame::Scene *scene) {
        this->_position = PVector2D::Vector2D<float>(0.0,0.0);
        this->_name = name;
        this->_parentScene = scene;
    }

    GameObject::GameObject (std::string name, std::string pngPath, PGame::Scene *scene) {
        this->_position = PVector2D::Vector2D<float>(0.0,0.0);
        this->_name = name;
        this->_parentScene = scene;
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

    std::string GameObject::getBodyType (void) {
        return this->_body_type;
    }

    void GameObject::setBodyType (std::string bt) {
        if (bt == "none" || bt == "static" || bt == "kinematic") {
            this->_body_type = bt;

        }
    }

    PVector2D::Vector2D<float> GameObject::getPos () {
        return this->_position;
    }

    void GameObject::setPos (PVector2D::Vector2D<float> newVec) {
        this->_position = newVec;
    }

    void GameObject::setXPos (float x) {
        this->_position.setX(x);
    }

    void GameObject::setYPos (float y) {
        this->_position.setY(y);
    }

    PVector2D::Vector2D<float> *GameObject::getVelocity (void) {
        return this->_velocity;
    }

    PGame::Scene *GameObject::getParentScene (void) {
        return this->_parentScene;
    }

    bool GameObject::hasHitBox (void) {
        bool pred = false;

        if (this->getHitBox() != NULL) {
            pred = true;
        }

        return pred;
    }

    void GameObject::setShowHitBox (void) {
        this->_show_hitbox = true;
    }

    void GameObject::clearShowHitBox (void) {
        this->_show_hitbox = false;
    }

    bool GameObject::getShowHitBox (void) {
        return this->_show_hitbox;
    }

    HitBox *GameObject::getHitBox (void) {
        return this->_hitbox;
    }

    void GameObject::setHitBox (HitBox *hb) {
        this->_hitbox = hb;
    }

    bool GameObject::isRenderable (void) {
        return this->_renderable;
    }

    void GameObject::setRenderable (void) {
        this->_renderable = true;
    }

    void GameObject::clearRenderable (void) {
        this->_renderable = false;
    }

    bool GameObject::isMovable (void) {
        return this->_movable;
    }

    void GameObject::setMovable (void) {
        this->_movable = true;
    }

    void GameObject::clearMovable (void) {
        this->_movable = false;
    }

    void GameObject::inputController(const Uint8 *keystates) {}
    void GameObject::move(double dt) {}
    void GameObject::render(void) {}
    GameObject::~GameObject () {}
}
