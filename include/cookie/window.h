#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace cookie
{
    class Window
    {
    private:
        SDL_Window *window_ = nullptr;
        SDL_Renderer *renderer_ = nullptr;
        int w_;
        int h_;
        std::string title_;

    public:
        Window() = default;
        Window(const Window &) = delete;

        Window(const std::string &title, int w, int h);
        ~Window();

        bool Init(const std::string &title, int w, int h);
        bool Fill(const SDL_Color &color);
        void Update();

        operator SDL_Window *() { return window_; }
        operator SDL_Renderer *() { return renderer_; }

        int w() const { return w_; }
        int h() const { return h_; }
        std::string title() const { return title_; }
    };
}