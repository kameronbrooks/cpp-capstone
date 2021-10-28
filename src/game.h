#ifndef GAME_H
#define GAME_H
#include "input_controller.h"
#include "renderer.h"
#include "board.h"
#include "game_state.h"

class Game: public InputControllerTarget  {
private:
    
    static Game* _instance;
    GameState* _state;


    InputController _input;
    Renderer _renderer;
    bool _running;
    
    
    
public:
    Game();
    ~Game();

    static Game* getInstance();

    void StartGame();
    GameState* getState();

    void render();

    void onExitApplication();
    void onMouseDown(int x, int y);
    void onMouseUp(int x, int y);
    void onMouseMove(int x, int y);
    
};

#endif