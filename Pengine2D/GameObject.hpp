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
#include "Vector2D.hpp"

namespace PGameObject {
    // this will mostly be extended by other classes
    // for use within a scene
    class GameObject {
    public:
        GameObject();
        GameObject(std::string);
        ~GameObject();

        std::string getTag(void);
        void setTag(std::string);
        std::string getName(void);
        void setName(std::string);

        PVector2D::Vector2D<int> getPos();
        void setPos(PVector2D::Vector2D<int>);
        void setXPos(int x);
        //void setXPos(float x);
        void setYPos(int y);
        //void setYPos(float y);

    private:
        std::string _tag = "";
        std::string _name = "";
        //template PVector2D::Vector2D<class T> _position;
        //PVector2D::Vector2D _position;
        //PVector2D::Vector2D<class T> _position;
        PVector2D::Vector2D<int> _int_position = PVector2D::Vector2D<int>(0,0);
        //PVector2D::Vector2D<float> _float_position;

    };
}

#endif /* GameObject_hpp */
