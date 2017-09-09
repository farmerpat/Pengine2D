//
//  Scene.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

// we really don't want to be including these all over the place.
// find out if they each need their own ifndef as well
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL2/sdl.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "GameObject.hpp"

namespace PGame {
    class Game;

    class Scene {
    public:
        Scene();
        Scene(Game*);
        ~Scene();
        void addGameObject(PGameObject::GameObject);
        PGameObject::GameObject *getGameObjectByName(std::string);
        void destroy(void);
        virtual void init(void) = 0;

    protected:
        bool _initialized = false;
        std::vector<PGameObject::GameObject> _gameObjects;
        SDL_Surface *_surface = NULL;
        Game *_parentGame = NULL;

    };
}
#endif /* Scene_hpp */
