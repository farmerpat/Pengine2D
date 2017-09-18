//
//  Camera.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/17/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "Camera.hpp"

namespace PGame {
    Camera::Camera (void) {
        this->_viewport = new SDL_Rect();
    }

    Camera::Camera (int w, int h) : GameObject() {
        this->_viewport = new SDL_Rect();
        this->_viewport->x = this->getPos().getX();
        this->_viewport->y = this->getPos().getY();
        this->_viewport->w = w;
        this->_viewport->h = h;

    }

    SDL_Rect *Camera::getViewPort (void) {
        return this->_viewport;
    }

    int Camera::getViewPortWidth (void) {
        int w = 0;

        if (this->_viewport != NULL) {
            w = this->_viewport->w;
        }

        return w;
    }

    int Camera::getViewPortHeight (void) {
        int h = 0;

        if (this->_viewport != NULL) {
            h = this->_viewport->h;
        }

        return h;
    }

    void Camera::setViewportWidth (int w) {
        if (this->_viewport != NULL) {
            this->_viewport->w = w;

        }
    }

    void Camera::setViewportHeight (int h) {
        if (this->_viewport != NULL) {
            this->_viewport->h = h;

        }
    }

    void Camera::updatePos (void) {
        int x = (int)this->getPos().getX();
        int y = (int)this->getPos().getY();

        this->_viewport->x = x;
        this->_viewport->y = y;
    }
}
