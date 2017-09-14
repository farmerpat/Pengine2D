//
//  PrimitiveRect.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/14/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef PrimitiveRect_hpp
#define PrimitiveRect_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "HitBox.hpp"

namespace PGame {
    class PrimitiveRect: public GameObject {
    public:
        PrimitiveRect();
        PrimitiveRect(int, int, int, int);
        void setColor(SDL_Color);
        void render(void);
        void initHitBox(void);

    private:
        SDL_Rect *_rect = NULL;
        HitBox *_hitbox = NULL;

    };
}
#endif /* PrimitiveRect_hpp */
