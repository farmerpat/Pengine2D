//
//  GameObject.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

// we really don't want to be including these all over the place.
// find out if they each need their own ifndef as well
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <SDL2/sdl.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "Scene.hpp"
#include "Vector2D.hpp"

namespace PGame {
    class Scene;

    class GameObject {
    public:
        GameObject();
        GameObject(std::string);
        GameObject (std::string, Scene);
        ~GameObject();

        std::string getTag(void);
        void setTag(std::string);
        std::string getName(void);
        void setName(std::string);

        PVector2D::Vector2D<int> getPos();
        void setPos(PVector2D::Vector2D<int>);
        void setXPos(int x);
        void setYPos(int y);

        Scene *getParentScene(void);

    private:
        std::string _tag = "";
        std::string _name = "";
        PVector2D::Vector2D<int> _int_position = PVector2D::Vector2D<int>(0,0);
        Scene *_parentScene;

    };
}

#endif /* GameObject_hpp */
