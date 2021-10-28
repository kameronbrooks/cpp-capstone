#include "renderer.h"
#include <SDL2/SDL_image.h>


Renderer::Renderer(int windowWidth, int windowHeight) {
    if (SDL_Init( SDL_INIT_VIDEO) < 0 ) {
        throw "failed to initialize SDL";
    }

    _window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN );
    if(_window == nullptr) {
        throw "failed to create window";
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        throw "failed to load img module";
    }

    _surface = SDL_GetWindowSurface(_window);

    SDL_FillRect(_surface, NULL, SDL_MapRGB( _surface->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(_window);

    SDL_Delay(2000);


}
Renderer::Renderer(Renderer&& other) {
    _surface = other._surface;
    _window = other._window;

    other._window = nullptr;
    other._surface = nullptr;
}
Renderer::Renderer(const Renderer& other) {
    
}

Renderer& Renderer::operator=(const Renderer& other) {
    throw "Renderer should not be copied";
}
Renderer& Renderer::operator=(Renderer&& other) {
    if(&other != this) {
        _surface = other._surface;
        _window = other._window;

        other._surface = nullptr;
        other._window = nullptr;
    }
    return *this;
}

void Renderer::drawSprite(Sprite* sprite, int x, int y, int w, int h) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    //SDL_BlitScaled(_handle, NULL, )
}
    
Renderer::~Renderer() {
    SDL_FreeSurface(_surface);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}