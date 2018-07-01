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
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Scene.hpp"
#include "Vector2D.hpp"
#include "Camera.hpp"

namespace PGame {
    class Scene;
    class HitBox;
    //class Camera;

    class GameObject {
    public:
        GameObject();
        GameObject(std::string);
        GameObject (std::string, Scene*);
        GameObject (std::string, std::string, Scene*);
        ~GameObject();

        std::string getTag(void);
        void setTag(std::string);
        std::string getName(void);
        void setName(std::string);
        std::string getBodyType(void);
        void setBodyType(std::string);

        PVector2D::Vector2D<float> getPos();
        void setPos(PVector2D::Vector2D<float>);
        void setXPos(float x);
        void setYPos(float y);
        virtual PVector2D::Vector2D<float>* getVelocity(void);

        bool isRenderable(void);
        void setRenderable(void);
        void clearRenderable(void);
        bool isMovable(void);
        void setMovable(void);
        void clearMovable(void);

        bool hasHitBox(void);
        void setShowHitBox(void);
        void clearShowHitBox(void);
        bool getShowHitBox (void);
        HitBox *getHitBox(void);
        void setHitBox(HitBox*);

        virtual bool isColliding(std::vector<GameObject*> c, std::vector<GameObject>::size_type i) { return false; }
        virtual void resolveCollisions(std::vector<GameObject*> c, std::vector<GameObject>::size_type i) { }
        virtual void inputController(const Uint8*);
        virtual void move(double);
        virtual void render(void);
        Scene *getParentScene(void);

    private:
        std::string _tag = "";
        std::string _name = "";
        std::string _body_type = "none";
        bool _renderable = false;
        bool _movable = false;
        PVector2D::Vector2D<float> _position = PVector2D::Vector2D<float>(0.0,0.0);
        PVector2D::Vector2D<float> *_velocity = NULL;
        Scene *_parentScene;
        HitBox *_hitbox = NULL;
        bool _show_hitbox = false;

    };
}

#endif /* GameObject_hpp */
