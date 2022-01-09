#include "cookie.h"
#include <SDL.h>

int main(int argc, char *argv[])
{
    using namespace cookie;

    Initializer initer;
    initer.InitSdl(SDL_INIT_VIDEO);

    Window window("Cookie Test", 960, 540);

    bool running = true;

    while (running)
    {
        SDL_Event e;

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
            }
        }

        window.Fill(SDL_Color{30, 30, 50, 255});
        window.Draw();
    }

    return 0;
}