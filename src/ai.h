#ifndef AI_H
#define AI_H
#include "globals.h"
#include "game_state.h"
#include <mutex>

class Game;

class AI {
private:
    AIState _aiState;
    Cell* _targetCell;
    std::mutex _targetCellMutex;
    std::mutex _stateMutex;
    Game* _game;
    GameState* _gameState;
public:
    AI(Game* game);
    AIState getState();
    Cell* getTargetCell();
    bool hasTargetCell();
    void think();
    void update();
};


#endif