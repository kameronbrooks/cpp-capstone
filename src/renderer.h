#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>

#include <memory>
#include "sprite.h"

class Renderer {
private:
    SDL_Window* _window;
    SDL_Surface* _surface;

public:
    Renderer(int windowWidth, int windowHeight);
    Renderer(Renderer&& other);
    Renderer(const Renderer& other);

    Renderer& operator=(const Renderer& other);
    Renderer& operator=(Renderer&& other);

    void drawSprite(Sprite* sprite, int x, int y, int w, int h);


    ~Renderer();

};

#endif