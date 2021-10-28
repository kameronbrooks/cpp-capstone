
#include <iostream>
#include "renderer.h"
#include "input_controller.h"
#include "game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main() {

    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    Sprite* sprite = renderer.LoadSprite("../img/king_black.png");

    renderer.clear();
    renderer.drawSprite(sprite, 100,10, 100,100);

    renderer.updateScreen();

    SDL_Delay(2000);

    std::cout << " Project" <<std::endl;
    std::cin;
    return 0;
}