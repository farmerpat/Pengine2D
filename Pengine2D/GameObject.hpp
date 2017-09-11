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

        PVector2D::Vector2D<float> getPos();
        void setPos(PVector2D::Vector2D<float>);
        void setXPos(float x);
        void setYPos(float y);

        bool isRenderable(void);
        void setRenderable(void);
        void clearRenderable(void);
        bool isMovable(void);
        void setMovable(void);
        void clearMovable(void);
        virtual void inputController(SDL_Event);
        virtual void move(double);
        virtual void render(void);
        Scene *getParentScene(void);

    private:
        std::string _tag = "";
        std::string _name = "";
        bool _renderable = false;
        bool _movable = false;
        PVector2D::Vector2D<float> _position = PVector2D::Vector2D<float>(0.0,0.0);
        Scene *_parentScene;

    };
}

#endif /* GameObject_hpp */
