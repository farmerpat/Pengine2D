//
//  Timer.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/11/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "Timer.hpp"

namespace PGame {
    Timer::Timer (void) {
        this->_startTicks = 0;
        this->_pausedTicks = 0;
        this->_started = false;
        this->_paused = false;

    }

    void Timer::start (void) {
        this->_startTicks = SDL_GetTicks();
        this->_pausedTicks = 0;
        this->_started = true;
        this->_paused = false;

    }

    void Timer::stop (void) {
        this->_started = false;
        this->_paused = false;
        this->_startTicks = 0;
        this->_pausedTicks = 0;

    }

    void Timer::pause (void) {
        if (this->_started && !this->_paused) {
            this->_paused = true;
            this->_pausedTicks = SDL_GetTicks() - this->_startTicks;
            this->_startTicks = 0;

        }
    }

    void Timer::unpause (void) {
        if (this->_started && this->_paused) {
            this->_startTicks = SDL_GetTicks() - this->_pausedTicks;
            this->_pausedTicks = 0;
            this->_paused = false;

        }
    }

    Uint32 Timer::getTicks (void) {
        Uint32 time = 0;

        if (this->_started) {
            if (this->_paused) {
                time = this->_pausedTicks;

            } else {
                time = SDL_GetTicks() - this->_startTicks;

            }
        }

        return time;
    }

    bool Timer::isStarted (void) { return this->_started; }
    bool Timer::isPaused (void) { return this->_paused; }
}
