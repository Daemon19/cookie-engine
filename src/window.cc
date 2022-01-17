#include <SDL2/SDL.h>
#include <stdexcept>
#include <string>

#include "log.h"
#include "window.h"

namespace cookie
{
    bool Window::Init(const std::string &title, int w, int h)
    {
        w_ = w;
        h_ = h;
        title_ = title;

        window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED, w, h, 0);
        if (window_ == nullptr)
        {
            log::SdlError("Gagal membuat window");
            return false;
        }

        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer_ == nullptr)
        {
            log::SdlError("Gagal membuat renderer");
            return false;
        }

        return true;
    }

    Window::Window(const std::string &title, int w, int h)
    {
        if (!Init(title, w, h))
            throw std::runtime_error("Gagal membuat objek Window");
    }

    Window::~Window()
    {
        if (window_ != nullptr)
            SDL_DestroyWindow(window_);

        if (renderer_ != nullptr)
            SDL_DestroyRenderer(renderer_);
    }

    bool Window::Fill(const SDL_Color &color)
    {
        return (SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a) == 0 &&
                SDL_RenderClear(renderer_) == 0);
    }

    void Window::Update()
    {
        SDL_RenderPresent(renderer_);
    }
}