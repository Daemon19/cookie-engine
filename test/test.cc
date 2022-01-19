#include <SDL2/SDL.h>
#include <cookie/cookie.h>

int main()
{
    using namespace cookie;

    const SDL_Color kBackgroundColor = {20, 20, 30, 255};

    Initializer::InitSdl(Initializer::kInitVideo);
    log::Info("Berhasil menginisialisasi SDL");

    // log::Info("Berhasil membuat log library!");
    // log::Warn("Bahaya, hehehe...");
    // log::Error("Ada masalah bang");
    // log::SdlError("Ada SDL error bang");

    Window window("Cookie Engine Test", 960, 540);
    log::Info("Berhasil membuat window");

    bool game_running = true;
    while (game_running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                game_running = false;
            }
        }

        window.Fill(kBackgroundColor);
        window.Update();
    }
}