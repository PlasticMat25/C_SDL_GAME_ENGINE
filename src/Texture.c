#include "Texture.h"

SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, path);
    
    if(texture == NULL) {
        printf("Could not load texture %s", path);
        return NULL;
    }

    return texture;
}

void PreloadTextures(SDL_Renderer* renderer)
{
    playerTexture = LoadTexture("../res/player.png", renderer);
}

