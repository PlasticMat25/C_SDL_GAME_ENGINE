#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* playerTexture;

static SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer);
void PreloadTextures(SDL_Renderer* renderer);

