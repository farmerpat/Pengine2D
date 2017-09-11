//
//  Timer.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/11/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

/*
 * the base of this was jacked shamelessly from
 * http://lazyfoo.net/tutorials/SDL/
 */

#include <SDL2/sdl.h>

namespace PGame {
    class Timer {
    public:
        Timer();

        void start(void);
        void stop(void);
        void pause(void);
        void unpause(void);

        Uint32 getTicks(void);
        bool isStarted(void);
        bool isPaused(void);

    private:
        Uint32 _startTicks;
        Uint32 _pausedTicks;
        bool _paused;
        bool _started;

    };
}

#endif /* Timer_hpp */
