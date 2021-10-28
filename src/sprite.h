#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <mutex>

class Renderer;

class Sprite {
public:
    enum State:uint8_t{Empty, Loading, Loaded};

     std::string name;
     
     Sprite(const Sprite& other);
     Sprite(Sprite&& other);
     Sprite& operator=(const Sprite& other);
     Sprite& operator=(Sprite&& other);
     ~Sprite();

     static Sprite* LoadPNG(std::string path);

     State getState() const;
     bool isLoaded() const;

     SDL_Texture* dataHandle() const;
     
private:
    SDL_Texture* _handle;
    int _width;
    int _height;
    State _state;
    std::mutex _mutex;
    
    Sprite(SDL_Texture* handle, int width, int height);

    friend class Renderer;

};


#endif