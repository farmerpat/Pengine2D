//
//  Texture.cpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/9/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#include "Texture.hpp"

namespace PTexture {
    Texture::Texture () {
        this->_mTexture = NULL;
        this->_mWidth = 0;
        this->_mHeight = 0;
    }

    Texture::~Texture () {
        this->free();
    }

    void Texture::setTargetRenderer (SDL_Renderer *r) {
        this->_targetRenderer = r;
    }

    SDL_Renderer *Texture::getTargetRenderer () {
        return this->_targetRenderer;
    }

    void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
        SDL_SetTextureColorMod(this->_mTexture, red, green, blue);
    }

    void Texture::render(int x, int y, SDL_Rect *clip) {
        SDL_Rect renderQuad = {
            x,
            y,
            this->_mWidth,
            this->_mHeight
        };

        if (clip != NULL) {
            renderQuad.w = clip->w;
            renderQuad.h = clip->h;
        }

        // clip is rect selection from _mTexture
        // renderQuad is rect destination on _targetRenderer
        SDL_RenderCopy(this->_targetRenderer, this->_mTexture, clip, &renderQuad);
    }

    bool Texture::loadFromFile(std::string path) {
        bool success = true;
        // get rid of preexisting texture
        free();
        SDL_Texture *newTexture = NULL;

        SDL_Surface *loadedSurface = IMG_Load(path.c_str());

        if (loadedSurface == NULL) {
            success = false;

        } else {
            // wut?
            SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xff, 0xff));
            newTexture = SDL_CreateTextureFromSurface(this->_targetRenderer, loadedSurface);

            if (newTexture == NULL) {
                success = false;

            } else {
                this->_mWidth = loadedSurface->w;
                this->_mHeight = loadedSurface->h;
            }

            SDL_FreeSurface(loadedSurface);
        }

        this->_mTexture = newTexture;

        return success;
    }

    void Texture::free () {
        if (this->_mTexture != NULL) {
            SDL_DestroyTexture (this->_mTexture);
            this->_mTexture = NULL;
            this->_mWidth = 0;
            this->_mHeight = 0;

        }
    }

    int Texture::getWidth () {
        return this->_mWidth;
    }

    int Texture::getHeight () {
        return this->_mHeight;
    }
}
