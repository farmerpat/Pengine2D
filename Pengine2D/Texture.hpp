//
//  Texture.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/9/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <string>
#include <SDL2/sdl.h>
#include <SDL2_image/SDL_image.h>

/*
 * the base of this was jacked shamelessly from
 * http://lazyfoo.net/tutorials/SDL/
 */
namespace PTexture {
    class Texture {
    public:
        Texture();
        ~Texture();
        
        void setTargetRenderer(SDL_Renderer *);
        SDL_Renderer *getTargetRenderer();
        bool loadFromFile(std::string path);
        void free();

        // set color modulation
        void setColor(Uint8 red, Uint8 green, Uint8 blue);

        // render mTexture at a given point
        // can render a poriton of it as specified by clip
        void render(int x, int y, SDL_Rect *clip = NULL);

        int getWidth();
        int getHeight();

    private:
        SDL_Texture *_mTexture;
        SDL_Renderer *_targetRenderer;
        int _mWidth;
        int _mHeight;

    };
}

#endif /* Texture_hpp */
