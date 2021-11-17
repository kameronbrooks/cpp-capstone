
#include <iostream>
#include "renderer.h"
#include "input_controller.h"
#include "game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main() {
    Game game;
    std::cout << " Starting" <<std::endl;
    game.startGame();
    return 0;
}