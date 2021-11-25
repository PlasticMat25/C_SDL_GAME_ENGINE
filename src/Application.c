#include "Application.h"

#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Vector2.h"
#include "Globals.h"

void Run();
void Update();
void Render();
void Destroy();
void Init();

void HandleEvents();

int isRunning = 0;

SDL_Window* window;
SDL_Renderer* renderer;
Graphics2D* g;

Vector2* position;
Vector2* vector;

const Color white   = (Color){255, 255, 255, 255};
const Color red     = (Color){255, 0, 0, 255};
const Color pink    = (Color){255, 0, 255, 255};


Application* CreateApplication( const char* title,
                                int x,
                                int y,
                                int w,
                                int h,
                                int fullscreen)
{    
    SDL_Init(SDL_INIT_EVERYTHING);
    Application* app = malloc(sizeof(Application));

    window = SDL_CreateWindow(title, x, y, w, h, fullscreen);    
    if(window == NULL) 
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return NULL;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if(renderer == NULL) 
    {
        printf("Could not create renderer: %s\n", SDL_GetError());
        return NULL;
    }

    g = GetGraphics(renderer);

    PreloadTextures(renderer);
    app->Run = &Run;
    return app;  
}

void Init()
{
    isRunning = 1;
	
	position = InitializeVector2(10, HEIGHT / 2);
	vector = InitializeVector2(120, 200);
}

void Run()
{
    
	Init();

    while(isRunning) {
        HandleEvents();
        Update();
        IUpdate();
        Render();
        SDL_Delay(10);
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
            case SDL_QUIT:
                isRunning = 0;
                printf("Not running :(\n");
                break;
            case SDL_KEYDOWN:
                SetKey(event.key.keysym.sym, KEY_DOWN);
                break;
            case SDL_KEYUP:                
                SetKey(event.key.keysym.sym, KEY_UP);
                break;
            default: break;        
        }
    }
}

void Update()
{
    if(KeyDown(SDLK_a))printf("KeyDown(HOLD)!\n");
    if(KeyPress(SDLK_s))printf("Key S is down!\n");
    if(KeyUp(SDLK_s))printf("Key S is up!\n");        
}

void Render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    g->DrawRect(10, 10, 100, 100, &white);
    g->DrawRect(50, 100, 80, 100, &pink);
    g->DrawRect(150, 150, 100, 200, &red);
    g->DrawTexture(50, 50, 128, 128, playerTexture);
    g->DrawTexture(10, 220, 128, 128, playerTexture);
    g->DrawTexture(90, 350, 128, 128, playerTexture);
	g->DrawVector(position, vector, &red);
	SDL_RenderPresent(renderer);
}

void Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
