//
//  Game.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "Game.hpp"
#include "Scene.hpp"

namespace PGame {
    Game::Game () {}
    Game::Game (std::string title) {
        this->_title = title;
    }

    Game::Game (std::string title, std::vector<Scene*> scenes) {
        this->_title = title;
        this->_scenes = scenes;
        this->_numScenes = this->_scenes.size();

        if (this->_numScenes > 0) {
            this->_activeSceneNumber = 0;
            this->_activeScene = this->_scenes.at(this->_activeSceneNumber);

        }
    }

    Game::~Game () {
        this->destroy();
    }

    void Game::setTitle (std::string title) {
        if (!this->_initializationComplete) {
            this->_title = title;

        }
    }

    void Game::setScreenWidth (int w) {
        if (!this->_initializationComplete) {
            this->_SCREEN_WIDTH = w;

        }
    }

    int Game::getScreenWidth (void) {
        return this->_SCREEN_WIDTH;
    }

    void Game::setScreenHeight (int h) {
        if (!this->_initializationComplete) {
            this->_SCREEN_HEIGHT = h;

        }
    }

    int Game::getScreenHeight (void) {
        return this->_SCREEN_HEIGHT;
    }

    void Game::setBackgroundColor (SDL_Color color) {
        if (!this->_initializationComplete) {
            this->_bgColor =  color;

        }
    }

    std::string Game::getTitle (void) {
        return this->_title;
    }

    bool Game::getInitializationComplete (void) {
        return this->_initializationComplete;
    }

    bool Game::getInitializationSucceeded (void) {
        return this->_initializationSucceeded;
    }

    SDL_Renderer *Game::getWindowRenderer (void) {
        return this->_windowRenderer;
    }

    void Game::addScene (Scene *s) {
        this->_scenes.push_back(s);

        if (this->_activeScene == NULL) {
            this->_activeScene = s;

        }
    }

    void Game::addScene(Scene *s, int ind) {
        if (ind <= this->_scenes.size()) {
            this->_scenes.insert(this->_scenes.begin()+ind, s);

        }
    }

    bool Game::init (void) {
        bool success = true;

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            success = false;
            printf ("unable to init video: %s\n", SDL_GetError());

        } else {
            this->_window = SDL_CreateWindow(
                this->_title.c_str(),
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                this->_SCREEN_WIDTH,
                this->_SCREEN_WIDTH,
                SDL_WINDOW_SHOWN

            );

            if (this->_window == NULL) {
                success = false;
                printf ("unable to create window: %s\n", SDL_GetError());

            } else {
                this->_windowRenderer = SDL_CreateRenderer(
                    this->_window,
                    -1,
                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

                );

                if (this->_windowRenderer == NULL) {
                    success = false;
                    printf ("unable to create window renderer: %s\n", SDL_GetError());

                } else {
                    int imgFlags = IMG_INIT_PNG;

                    if (! (IMG_Init(imgFlags) & imgFlags)) {
                        printf("sdl_img could not be initialized: %s\n", IMG_GetError());
                        success = false;

                    }
                }
            }
        }

        this->_initializationComplete = true;
        this->_initializationSucceeded = success;

        return success;
    }

    bool Game::getQuit (void) {
        return this->_quit;
    }

    void Game::setQuit (void) {
        this->_quit = true;
    }

    void Game::clearQuit (void) {
        this->_quit = false;
    }

    void Game::run (void) {
        // load the first scene

        while (!this->_quit) {
            // support window events at some point
            while (SDL_PollEvent(&this->_inputEvent) != 0) {
                if (this->_inputEvent.type == SDL_QUIT) {
                    this->setQuit();

                } else {
                    this->_activeScene->inputController(this->_inputEvent);
                    this->_activeScene->render();

                }
            }
        }
    }

    void Game::destroy () {
        // ITERATE OVER THE SCENES AND DESTROY THEM TOO

        if (this->_window != NULL) {
            SDL_DestroyWindow(this->_window);
            this->_window = NULL;
        }

        if (this->_windowRenderer != NULL) {
            SDL_DestroyRenderer(this->_windowRenderer);
            this->_windowRenderer = NULL;

        }
    }
}
