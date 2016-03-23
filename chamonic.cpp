#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *window = NULL;
SDL_Surface *screen1 = NULL;
SDL_Surface *picture = NULL;

int init();
int main(int argc, char *args[]){
    init();
    return 0;
}

int init()
{

    if (SDL_Init( SDL_INIT_VIDEO ) < 0)
    {
        printf("error %s",SDL_GetError());
    }
    else
    {
        window = SDL_CreateWindow("Charmonic",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

        if (window == NULL)
        {
            printf("error %s",SDL_GetError());
        }
        else
        {
            screen1 = SDL_GetWindowSurface(window);
            picture = IMG_Load("bg.png");
            SDL_BlitSurface(picture,NULL,screen1,NULL);
            SDL_UpdateWindowSurface(window);
            SDL_Delay(5000);

        }

    }
}
