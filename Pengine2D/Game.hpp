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
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Scene.hpp"

namespace PGame {
    class Game {
    public:
        Game();
        Game(std::string);
        Game(std::string, std::vector<Scene*>);
        ~Game();

        void setScreenWidth(int);
        int getScreenWidth(void);
        void setScreenHeight(int);
        int getScreenHeight(void);
        void setBackgroundColor(SDL_Color);
        void setTitle(std::string);
        std::string getTitle(void);
        bool getQuit(void);
        void setQuit(void);
        void clearQuit(void);
        SDL_Renderer *getWindowRenderer(void);
        void addScene(Scene*);
        void addScene(Scene*, int);

        bool init(void);
        bool getInitializationComplete(void);
        bool getInitializationSucceeded(void);
        void run(void);
        void destroy(void);

    private:
        std::string _title = "";
        int _SCREEN_WIDTH = 640;
        int _SCREEN_HEIGHT = 480;
        bool _quit = false;
        SDL_Window *_window = NULL;
        SDL_Renderer *_windowRenderer = NULL;
        SDL_Color _bgColor;
        SDL_Event _inputEvent;

        std::vector<Scene*> _scenes;
        unsigned long _numScenes = 0;
        bool _initializationComplete = false;
        bool _initializationSucceeded = false;

        // to be controlled by a GameManager class
        int _activeSceneNumber = -1;
        Scene *_activeScene = NULL;

    };
}
#endif /* Game_hpp */
