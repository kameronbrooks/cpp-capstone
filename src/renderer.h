#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include "sprite.h"
#include "color.h"

class Renderer {
private:
    SDL_Window* _window;
    SDL_Renderer* _sdlRenderer;
    int _windowWidth;
    int _windowHeight;

public:
    Renderer(int windowWidth, int windowHeight);
    Renderer(Renderer&& other);
    Renderer(const Renderer& other);

    Renderer& operator=(const Renderer& other);
    Renderer& operator=(Renderer&& other);

    Sprite* LoadSprite(std::string&& path);

    void setRenderingColor(Color& color);
    void drawSprite(Sprite* sprite, int x, int y, int w, int h);
    void drawSprite(Sprite* sprite, int x, int y, int w, int h, Color& color);
    void drawRect(int x, int y, int w, int h, Color& color);

    int windowWidth();
    int windowHeight();

    void clear();
    void updateScreen();

    ~Renderer();

};

#endif