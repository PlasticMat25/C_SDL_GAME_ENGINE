#include "Application.h"
#include "Globals.h"
#include "Input.h"
#include "Graphics.h"
#include "Assets.h"

void HandleEvents();
void Update();
void Render();
void Destroy();
void Run();

SDL_Window* window;
SDL_Renderer* renderer;
int isRunning = 0;

Graphics2D* g;
Color c;

void Initialize(const char* title, int x, int y, int w, int h, int fullscreen)
{    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    window = SDL_CreateWindow(title, x, y, w, h, fullscreen);

    if(window == NULL) 
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    
    if(window == NULL) 
    {
        printf("Could not create renderer: %s\n", SDL_GetError());
        return;
    }

    PreloadTextures();
    g = GetRenderer(renderer);  
    Run();
}

void Run() {
    isRunning = 1;
    
    while(isRunning) {
        HandleEvents();
        Update();
        //Render();
        SDL_Delay(1);    
    }

    Destroy();
}

void HandleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_KEYDOWN:
                AddKey(event.key.keysym.scancode);    
                break;
            case SDL_KEYUP:
                RemoveKey(event.key.keysym.scancode);
                break;
            case SDL_QUIT:
                isRunning = 0;
                printf("Stop running..\n");                
                break;
            default:
                break;               
        }    
    }
}

void Update()
{
    if(KeyDown(SDL_SCANCODE_A)) {
        printf("Key Down A\n");    
    }
    if(KeyPress(SDL_SCANCODE_S)) {
        printf("Key Press S\n");    
    }
    if(KeyUp(SDL_SCANCODE_D)) {
        printf("Key Up D\n");    
    }

    IUpdate();
}

Color colors[5] = {
(Color){0,     255,    255,    255},
(Color){255,   0,      255,    255},
(Color){255,   255,    0,      255},
(Color){255,   0,      0,      255},
(Color){0,     255,    0,      255},
};

#include <time.h>
#include <stdlib.h>

void Render()
{
    srand(time(0));

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for(int i = 0; i < 1000; i++)
    {
        int x = random() % WIDTH;
        int y = random() % HEIGHT; 
        int w = random() % 100 + 1;
        int h = random() % 100 + 1;
        Color color = colors[random() % 5];
        g->DrawRect(&(SDL_Rect){x, y, w, h}, &color);    
    }
    
    g->DrawTexture(&(SDL_Rect){100, 20, 250, 420}, test_texture);

    SDL_RenderPresent(renderer);
}

void Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
