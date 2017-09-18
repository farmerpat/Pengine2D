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
#include "GameObject.hpp"
#include "Vector2D.hpp"

namespace PGame {
    class Camera : public GameObject {
    public:
        Camera(void);
        Camera(int, int);
        SDL_Rect *getViewPort(void);
        int getViewPortWidth(void);
        int getViewPortHeight(void);
        void setViewportWidth(int);
        void setViewportHeight(int);
        void updatePos(void);

    private:
        SDL_Rect *_viewport = NULL;

    };
}


#endif /* Camera_hpp */
