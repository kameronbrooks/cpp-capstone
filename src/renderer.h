#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include "sprite.h"

class Renderer {
private:
    SDL_Window* _window;
    SDL_Renderer* _sdlRenderer;

public:
    Renderer(int windowWidth, int windowHeight);
    Renderer(Renderer&& other);
    Renderer(const Renderer& other);

    Renderer& operator=(const Renderer& other);
    Renderer& operator=(Renderer&& other);

    Sprite* LoadSprite(std::string&& path);

    void drawSprite(Sprite* sprite, int x, int y, int w, int h);


    void clear();
    void updateScreen();

    ~Renderer();

};

#endif