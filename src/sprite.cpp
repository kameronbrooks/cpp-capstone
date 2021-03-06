#include "sprite.h"

Sprite::Sprite(const Sprite& other) {
    throw "Cannot copy texture this way";
}
Sprite::Sprite(Sprite&& other) {
    _handle = other._handle;
    _height = other._height;
    _width = other._width;
    _state = other._state;

    other._handle = nullptr;
    other._height = 0;
    other._width = 0;
    other._state = State::Empty;
}
Sprite& Sprite::operator=(const Sprite& other) {
    throw "Cannot copy sprite this way";
}
Sprite& Sprite::operator=(Sprite&& other) {
    if (&other != this) {
        _handle = other._handle;
        _height = other._height;
        _width = other._width;
        _state = other._state;

        other._handle = nullptr;
        other._height = 0;
        other._width = 0;
        other._state = State::Empty;
    }
    return *this;
}
Sprite::~Sprite() {
    if(_handle != nullptr) {
        SDL_DestroyTexture(_handle);
    }
    _handle = nullptr;
    _state = State::Empty;
    _width = 0;
    _height = 0;
    name = "";
}




SDL_Texture* Sprite::dataHandle() const {
    return _handle;
}



Sprite::State Sprite::getState() const {
    std::unique_lock<std::mutex>(_mutex);
    return _state;
}
bool Sprite::isLoaded() const {
    std::unique_lock<std::mutex>(_mutex);
    return _state == State::Loaded;
}

Sprite::Sprite(SDL_Texture* handle, int width, int height) {
    _state = State::Loaded;
    _handle = handle;
    _width = width;
    _height = height;
}