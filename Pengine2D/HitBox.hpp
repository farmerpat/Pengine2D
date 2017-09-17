//
//  HitBox.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/14/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef HitBox_hpp
#define HitBox_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "GameObject.hpp"

namespace PGame {
    class HitBox : public GameObject {
    public:
        HitBox();
        HitBox(float, float, int, int);
        HitBox(SDL_Rect*);
        int getWidth(void);
        void setWidth(int);
        int getHeight(void);
        void setHeight(int);
        SDL_Rect *getRect(void);
        SDL_Color *getColor(void);
        void setColor(SDL_Color*);
        void updatePosition(void);
        bool isCollidingWith (HitBox*);
        std::string getCollisionLocation(HitBox*);

    private:
        SDL_Rect *_rect = NULL;
        SDL_Color *_color = NULL;

    };
}

#endif /* HitBox_hpp */
