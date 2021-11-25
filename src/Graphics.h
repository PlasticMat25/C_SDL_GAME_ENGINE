#pragma once

#include <SDL2/SDL.h>
#include "Vector2.h"

typedef struct {
    int r;
    int g;
    int b;
    int a;
} Color;

typedef struct {
    void (*DrawRect)(int x, int y, int w, int h, const Color* color);
    void (*DrawTexture)(int x, int y, int w, int h, SDL_Texture* texture);
    void (*DrawVector)(Vector2* position, Vector2* vector, const Color* color);
} Graphics2D;


Graphics2D* GetGraphics(SDL_Renderer* _renderer);
