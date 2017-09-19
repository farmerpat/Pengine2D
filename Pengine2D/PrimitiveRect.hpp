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
#include <string>
#include "Game.hpp"
#include "Scene.hpp"
#include "GameObject.hpp"
#include "HitBox.hpp"
#include "Camera.hpp"

namespace PGame {
    class PrimitiveRect: public GameObject {
    public:
        PrimitiveRect(void);
        PrimitiveRect(std::string);
        PrimitiveRect(std::string, SDL_Rect*, Scene*);
        void setColor(SDL_Color*);
        void setRect(SDL_Rect*);
        void render(void);
        // PrimitiveRect and Sprite could theoretically
        // descend from the same Parent class (Collidable or something)
        // just for the hitbox members and some kind of overridable
        // resolveCollisions function
        void initHitBox(void);

    private:
        SDL_Rect *_rect = NULL;
        SDL_Color *_color = NULL;

    };
}
#endif /* PrimitiveRect_hpp */
