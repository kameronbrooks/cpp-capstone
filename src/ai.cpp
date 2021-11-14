#include "ai.h"
#include "game.h"
#include <thread>
#include <chrono>
#include <random>
#include <cstdlib>

AI::AI(Game* game) {
    _game = game;
    _aiState = AIState::Waiting;
    _targetCell = nullptr;
}

AIState AI::getState() {
    std::lock_guard<std::mutex> lock(_stateMutex);
    return _aiState;
}
Cell* AI::getTargetCell() {
    std::lock_guard<std::mutex> lock(_targetCellMutex);
    return _targetCell;
}
bool AI::hasTargetCell() {
    std::lock_guard<std::mutex> lock(_targetCellMutex);
    return _targetCell != nullptr;
}
void AI::think() {
    _gameState = _game->getState();
    std::thread t([this]() {
        std::unique_lock<std::mutex> lock(_stateMutex);
        _aiState = AIState::Calculating;
        lock.unlock();

        std::unique_lock<std::mutex> cellLock(_targetCellMutex);
        cellLock.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        int i = 0;
        int looks = std::rand() % 10;
        while(i < looks) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500 + (std::rand() % 1000) ));
            int x = std::rand() % BOARD_WIDTH;
            int y = std::rand() % BOARD_HEIGHT;
            cellLock.lock();
            _targetCell = _gameState->getBoard().getCell(x,y);
            cellLock.unlock();
        }


        lock.lock();
        _aiState = AIState::Waiting;
    });
    t.detach();
    
}

void AI::update() {
    if(_aiState == AIState::Waiting && !_game->isPlayerTurn()!=0) {
        think();
    }
}