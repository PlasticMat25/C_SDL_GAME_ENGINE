#include "Graphics.h"

SDL_Renderer* renderer;
static Graphics2D* graphics = NULL;

void DrawRect(const SDL_Rect* rect, const Color* c)
{
    SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, c->a);
    SDL_RenderDrawRect(renderer, rect);    
}

void DrawTexture(const SDL_Rect* rect, SDL_Texture* texture)
{
    SDL_RenderCopy(renderer, texture, NULL, rect);
}

SDL_Texture* LoadTexture(const char* path) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, path);
    
    if(texture == NULL) {
        printf("Couldn't load texture: %s", path);
        return NULL;    
    }

    return texture;
}

Graphics2D* GetRenderer(SDL_Renderer* _renderer)
{
    if(graphics == NULL)
    {
        graphics = malloc(sizeof(Graphics2D));

        graphics->DrawRect      = &DrawRect;
        graphics->DrawTexture   = &DrawTexture;

        renderer = _renderer;
    }

    return graphics;
}
