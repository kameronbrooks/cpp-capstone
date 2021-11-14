#include "renderer.h"
#include <mutex>
#include <thread>
#include <future>



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
    SDL_SetRenderDrawBlendMode(_sdlRenderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor( _sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    _windowWidth = windowWidth;
    _windowHeight = windowHeight;
    


}

void Renderer::clear() {
    std::lock_guard<std::mutex> lock(_sdlMutex);
    SDL_SetRenderDrawColor( _sdlRenderer, 0, 0, 0, 0 );
    SDL_RenderClear(_sdlRenderer);
}
void Renderer::updateScreen() {
    std::lock_guard<std::mutex> lock(_sdlMutex);
    SDL_RenderPresent(_sdlRenderer);
}

Sprite* Renderer::LoadSprite(std::string&& path) {
    std::unique_lock<std::mutex> lock(_sdlMutex);
    SDL_Surface* temp = IMG_Load(path.c_str());
    int w = temp->w, h = temp->h;
    if (temp == nullptr) {
        throw "Failed to load image file: " + path;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface( _sdlRenderer , temp );
    SDL_FreeSurface(temp);
    lock.unlock();

    Sprite* output = new Sprite(tex, w, h);

    
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

void Renderer::setRenderingColor(Color& color) {
    std::unique_lock<std::mutex> lock(_sdlMutex);
    SDL_SetRenderDrawColor(_sdlRenderer, color[0], color[1], color[2], color[3]);
}

void Renderer::drawSprite(Sprite* sprite, int x, int y, int w, int h) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = _windowHeight - h - y;
    rect.w = w;
    rect.h = h;
    std::unique_lock<std::mutex> lock(_sdlMutex);
    SDL_RenderCopy(_sdlRenderer,sprite->_handle, NULL, &rect);
}

void Renderer::drawSprite(Sprite* sprite, int x, int y, int w, int h, Color& color) {
    
    SDL_Rect rect;
    rect.x = x;
    rect.y = _windowHeight - h - y;
    rect.w = w;
    rect.h = h;
    std::unique_lock<std::mutex> lock(_sdlMutex);
    SDL_SetTextureColorMod(sprite->_handle, color[0], color[1], color[2]);
    SDL_RenderCopy(_sdlRenderer,sprite->_handle, NULL, &rect);
}


void Renderer::drawRect(int x, int y, int w, int h, Color& color) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = _windowHeight - h - y;
    rect.w = w;
    rect.h = h;
    std::unique_lock<std::mutex> lock(_sdlMutex);
    SDL_SetRenderDrawColor(_sdlRenderer, color[0], color[1], color[2], color[3]);
    SDL_RenderFillRect(_sdlRenderer, &rect);
}

int Renderer::windowWidth() const {
    return _windowWidth;
}
int Renderer::windowHeight() const {
    return _windowHeight;
}

    
Renderer::~Renderer() {
    SDL_DestroyRenderer(_sdlRenderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}