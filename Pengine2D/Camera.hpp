//
//  Camera.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/17/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
//#include "GameObject.hpp"
#include "Vector2D.hpp"

namespace PGame {
    //class Camera : public GameObject {
    class Camera {
    public:
        Camera(void);
        Camera(int, int);
        SDL_Rect *getViewPort(void);
        int getViewPortWidth(void);
        int getViewPortHeight(void);
        void setViewportWidth(int);
        void setViewportHeight(int);
        void updatePos(void);
        // all this GameObject stuff being duplicated is dumb
        // GameObject should be a desendant of a Positionable class
        // or something that hass all this too, so that
        // Camera can be a child of that.
        // GO has things that Camera doesn't need, like velocity
        // refator.
        PVector2D::Vector2D<float> getPos();
        void setPos(PVector2D::Vector2D<float>);
        void setXPos(float x);
        void setYPos(float y);

    private:
        SDL_Rect *_viewport = NULL;
        PVector2D::Vector2D<float> _position = PVector2D::Vector2D<float>(0.0,0.0);

    };
}

#endif /* Camera_hpp */
