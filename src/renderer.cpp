#include "renderer.h"



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

    _sdlRenderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED );

    SDL_SetRenderDrawColor( _sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    


}

void Renderer::clear() {
    SDL_RenderClear(_sdlRenderer);
}
void Renderer::updateScreen() {
    SDL_RenderPresent(_sdlRenderer);
}

Sprite* Renderer::LoadSprite(std::string&& path) {
    SDL_Surface* temp = IMG_Load(path.c_str());
    if (temp == nullptr) {
        throw "Failed to load image file: " + path;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface( _sdlRenderer , temp );
    
    Sprite* output = new Sprite(tex, temp->w, temp->h);

    SDL_FreeSurface(temp);

    return output;
}


Renderer::Renderer(Renderer&& other) {
    _sdlRenderer = other._sdlRenderer;
    _window = other._window;

    other._window = nullptr;
    other._sdlRenderer = nullptr;
}
Renderer::Renderer(const Renderer& other) {
    
}

Renderer& Renderer::operator=(const Renderer& other) {
    throw "Renderer should not be copied";
}
Renderer& Renderer::operator=(Renderer&& other) {
    if(&other != this) {
        _sdlRenderer = other._sdlRenderer;
        _window = other._window;

        other._sdlRenderer = nullptr;
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
    SDL_RenderCopy(_sdlRenderer,sprite->_handle, NULL, &rect);
}

    
Renderer::~Renderer() {
    SDL_DestroyRenderer(_sdlRenderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}