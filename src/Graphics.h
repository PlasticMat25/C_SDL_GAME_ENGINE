#pragma once

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

typedef struct {
    int r;
    int g;
    int b;
    int a;
} Color;

typedef struct {
    void (*DrawRect)    (const SDL_Rect*, const Color*);
    void (*DrawTexture) (const SDL_Rect*, SDL_Texture*);
} Graphics2D;

Graphics2D* GetRenderer(SDL_Renderer* renderer);
SDL_Texture* LoadTexture(const char* path);
