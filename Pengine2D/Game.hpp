//
//  Game.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <SDL2/sdl.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "Scene.hpp"

namespace PGame {
    class Game {
    public:
        Game();
        Game(std::string);
        Game(std::string, std::vector<PScene::Scene>);
        ~Game();
        void setScreenWidth(int);
        void setScreenHeight(int);
        void setBackgroundColor(SDL_Color);
        void setTitle(std::string);
        void addScene(PScene::Scene);
        void addScene(PScene::Scene, int);
        bool init(void);
        std::string getTitle(void);
        bool getInitializationComplete(void);
        bool getInitializationSucceeded(void);
        void destroy(void);

    private:
        std::string _title = "";
        int _SCREEN_WIDTH = 640;
        int _SCREEN_HEIGHT = 480;
        SDL_Window *_window = NULL;
        SDL_Renderer *_windowRenderer = NULL;
        SDL_Color _bgColor;

        // a collection of scenes
        //PScene::Scene *_scenes = NULL;
        std::vector<PScene::Scene> _scenes;
        unsigned long _numScenes = 0;
        bool _initializationComplete = false;
        bool _initializationSucceeded = false;

        // to be controlled by a GameManager class
        int _activeSceneNumber = -1;
        PScene::Scene *_activeScene = NULL;

    };
}
#endif /* Game_hpp */
