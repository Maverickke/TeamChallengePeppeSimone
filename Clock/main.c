#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <time.h>
#include <Windows.h>

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        SDL_Log("Unable to initialize SDL : %s", SDL_GetError());
        return -1;
    }

    const char *title = "Clock";
    int x = SDL_WINDOWPOS_UNDEFINED;
    int y = SDL_WINDOWPOS_UNDEFINED;
    int w = 1024;
    int h = 800;
    Uint32 flags = 0;

    SDL_Window *window = SDL_CreateWindow(title, x, y, w, h, flags);

    if (!window)
    {
        SDL_Log("Unable to create without : %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        SDL_Log("Unable to create renderer : %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    SDL_Surface *surface = NULL;
    SDL_Texture *texture;

    surface = SDL_LoadBMP("lancetta.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        SDL_Log("Unable to create texture : %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    int running = 1;

    SYSTEMTIME str_t;

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }

        GetSystemTime(&str_t);

        SDL_Rect rect;
        rect.x = 50;
        rect.y = 50;
        rect.w = 1;
        rect.h = 1;

        SDL_Point center;

        int32_t width = 0;
        int32_t height = 0;
        double angle;

        SDL_QueryTexture(texture, NULL, NULL, &width, &height);

        rect.w = width;
        rect.h = height;

        rect.x = w * 0.5;
        rect.y = (h * 0.5) - rect.h;

        center.x = rect.w * 0.5;
        center.y = rect.h - (rect.w * 0.5);

        angle = 0;
        int32_t value = str_t.wSecond;
        double maxvalue = 60;

        double rotation = (double)(value / maxvalue);

        angle = 360 * rotation;

        //set current color.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //clear with the current color.
        SDL_RenderClear(renderer);
        // SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle, &center, SDL_FLIP_NONE);
        //set current color (red).
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return 0;
}