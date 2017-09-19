//
//  ExampleScene.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/9/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef ExampleScene_hpp
#define ExampleScene_hpp

#include <stdio.h>
#include "Scene.hpp"

namespace PGame {
    class ExampleScene: public Scene {
    public:
        ExampleScene();
        ExampleScene(Game*);
        ExampleScene (Game*, int, int);
        void init(void);

    };
}
#endif /* ExampleScene_hpp */
