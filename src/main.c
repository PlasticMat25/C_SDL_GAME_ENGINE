#include <SDL2/SDL.h>
#include <stdio.h>

#include "Application.h"
#include "Globals.h"

int main(int argc, char** argv)
{
    Application* game;
    game = CreateApplication(   TITLE, 
                                10, 
                                10, 
                                WIDTH, 
                                HEIGHT, 
                                0);

    game->Run();

    SDL_Quit();
    return 0;
}
