#ifndef GAME_H
#define GAME_H
#include "input_controller.h"
#include "renderer.h"
#include "board.h"
#include "game_state.h"

class Game {
private:
    Game();
    static Game _instance;
    GameState _state;


    InputController _input;
    Renderer _renderer;
    
    

public:
    static Game initializeGame(InputController&& input, Renderer&& renderer);

    static Game getInstance();

    void StartGame();
    GameState& getState();
};

#endif