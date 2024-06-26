//
//  Scene.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "GameObject.hpp"
#include "Camera.hpp"
#include "Vector2D.hpp"

namespace PGame {
    class Game;
    class GameObject;

    class Scene {
    public:
        Scene();
        Scene(Game*);
        Scene(Game*, int, int);
        ~Scene();
        void addGameObject(GameObject*);
        GameObject *getGameObjectByName(std::string);
        Game *getParentGame(void);
        void destroy(void);
        // virtual void render(void); ??
        void render(void);
        void move(double);
        void resolveCollisions(void);
        void applyDragAndGravity(double);
        void setCamera(Camera*);
        Camera *getCamera(void);
        void centerCameraAround(int, int);
        void moveCamera(int, int);
        // ?
        // the idea would be that
        // Game loads the
        // active scene and runs the main game loop
        // gets input
        // calls tick on the current scene
        // then scene can loop through its game objects,
        // passing all of them the SDL_Event in inputController
        // each scene will be responsible for handling its end conditions
        // when they are met via completion or death, they will tell Game
        // somehow, and it will load the next scene, if applicable
        // maybe they should tell the GameManager, which would be a property
        // of Game
        // to start, maybe they should just set a flag in Game so that it knows
        // at the top of the game loop, Game could check and see if the current scene
        // is done, and under what conditions.. there could be a specific game over
        // scene (stored seperately from the vector of scenes) that it could load, for instance
        virtual void init(void) = 0;
        virtual void inputController(const Uint8*);

    protected:
        bool _initialized = false;
        // this doesn't work for derived classes because of ojbect slicing
        // basically, if we push a dervied class onto the vector, only
        // the GameObject portion of the object is saved.
        // hence, pointers
        std::vector<GameObject*> _gameObjects;
        SDL_Surface *_surface = NULL;
        Game *_parentGame = NULL;
        Camera *_camera = NULL;
        SDL_Texture *_sceneTexture = NULL;

    };
}
#endif /* Scene_hpp */
