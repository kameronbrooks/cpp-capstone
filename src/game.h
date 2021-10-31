#ifndef GAME_H
#define GAME_H
#include "input_controller.h"
#include "renderer.h"
#include "board.h"
#include "game_state.h"
#include "globals.h"
#include "piece_types.h"

class Game: public InputControllerTarget  {
private:
    
    static Game* _instance;
    std::unique_ptr<GameState> _state;


    InputController _input;
    Renderer _renderer;
    bool _running;

    Pawn _pawnType;
    Knight _knightType;
    Bishop _bishopType;
    Rook _rookType;
    
    void placePieces();

    Cell* _hoverCell;
    Cell* _selectedCell;
    Color _uiColor;
    
public:
    Game();
    ~Game();

    static Game* getInstance();

    void loadGameData();
    void startGame();
    GameState* getState();

    void render();

    void onExitApplication();
    void onMouseDown(int x, int y);
    void onMouseUp(int x, int y);
    void onMouseMove(int x, int y);
    
};

#endif