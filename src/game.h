#ifndef GAME_H
#define GAME_H
#include "input_controller.h"
#include "renderer.h"
#include "board.h"

class Game {
private:
    Game();
    static Game _instance;

    InputController _input;
    Renderer _renderer;
    
    Board _board;

public:
    static Game initializeGame(InputController&& input, Renderer&& renderer);

    static Game getInstance();
};

#endif