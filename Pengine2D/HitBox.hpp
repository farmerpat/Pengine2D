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
#include "GameObject.hpp"

namespace PGame {
    class HitBox : public GameObject {
    public:
        HitBox();
        HitBox(float, float, int, int);
        int getWidth(void);
        void setWidth(int);
        int getHeight(void);
        void setHeight(int);
        SDL_Rect *getRect(void);
        SDL_Color *getColor(void);
        void setColor(SDL_Color*);
        void updatePosition(void);

    private:
        //float _width = 0.0;
        //float _height = 0.0;
        SDL_Rect *_rect = NULL;
        SDL_Color *_color = NULL;

    };
}

#endif /* HitBox_hpp */
