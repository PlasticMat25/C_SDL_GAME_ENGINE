#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void (*Run)();
} Application;

Application* CreateApplication( const char* title,
                                int x,
                                int y,
                                int w,
                                int h,
                                int fullscreen);
