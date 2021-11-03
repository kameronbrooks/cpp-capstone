#ifndef GAME_H
#define GAME_H
#include <chrono>
#include "input_controller.h"
#include "renderer.h"
#include "board.h"
#include "game_state.h"
#include "globals.h"
#include "piece_types.h"
#include "relation_matrix.h"

class Game: public InputControllerTarget  {
private:
    
    static Game* _instance;
    std::unique_ptr<GameState> _state;
    long _accum;
    std::chrono::_V2::high_resolution_clock::time_point _lastTime;

    
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
    Color _uiColor{100,255,100,100};
    Color _uiColor2{100,255,255,0};
    std::unique_ptr<Sprite> _moveIcon;
    
public:
    Game();
    ~Game();

    static Game* getInstance();

    void loadGameData();
    void startGame();
    GameState* getState();
    bool isPlayerTurn();

    void render();
    void drawMoves();

    void onExitApplication();
    void onMouseDown(int x, int y);
    void onMouseUp(int x, int y);
    void setMousePos(int x, int y);
    
};

#endif