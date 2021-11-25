#include "Graphics.h"

SDL_Renderer* renderer;
static Graphics2D* graphics = NULL;

void SetColor(const Color* color) {
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
}

void DrawRect(int x, int y, int w, int h, const Color* color)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
	SetColor(color);
    SDL_RenderDrawRect(renderer, &rect);
}

void DrawTexture(int x, int y, int w, int h, SDL_Texture* texture)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}


void DrawVector(Vector2* position, Vector2* vector, const Color* color){
	SetColor(color);
	Vector2* clone = CloneVector2(vector);
	Add(clone, position);
	
	SDL_RenderDrawLine(renderer, position->x, position->y, clone->x, clone->y);
}

Graphics2D* GetGraphics(SDL_Renderer* _renderer)
{
    if(graphics == NULL)
    {
        graphics = malloc(sizeof(Graphics2D));
        graphics->DrawRect = &DrawRect;
        graphics->DrawTexture = &DrawTexture;
        graphics->DrawVector = &DrawVector;
        renderer = _renderer;
    }

    return graphics;
}


