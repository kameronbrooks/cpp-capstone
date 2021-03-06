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

int AI::getCellValue(Cell* cell) {
    if(!cell->isOccupied())
        return 0;
    else
        return cell->getPiece()->getPieceType()->getId();
}

void AI::randomize(std::vector<Cell*>& list, int count) {
    int j = 0;
    while(j<count) {
        Cell* temp;
        for(int i = 1; i < list.size(); ++i) {
            
            int v0 = getCellValue(list[i-1]);
            int v1 = getCellValue(list[i]);
            if(v0 < v1) {
                temp = list[i];
                list[i] = list[i-1];
                list[i-1] = temp; 
            }
            else if(v0 == v1) {
                if((rand() % 10) < 3) {
                    temp = list[i];
                    list[i] = list[i-1];
                    list[i-1] = temp;         
                }
            }
            
        }
        ++j;
    }
}

void AI::think() {
    _gameState = _game->getState();
    std::thread t([this]() {
        std::unique_lock<std::mutex> lock(_stateMutex);
        _aiState = AIState::Calculating;
        lock.unlock();

        std::unique_lock<std::mutex> cellLock(_targetCellMutex);
        cellLock.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        int i = 0;
        
        std::vector<Cell*> potentialMoves;
        // Look for potential moves
        for(int x = 0; x < BOARD_WIDTH; ++x) {
            for(int y = 0; y < BOARD_HEIGHT; ++y) {
                Cell* cell = _game->getState()->getBoard().getCell(x,y);
                if((std::rand() % 400) < 50) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(10 + (std::rand() % 150) ));
                }
                
                for(auto a: _game->getState()->getActionMatrix()->items(x,y)) {
                    if(a->getPieceTeam() == PieceTeam::Black) {
                        if(cell->isOccupied()) {
                            potentialMoves.insert(potentialMoves.begin(), cell);
                        } else {
                            potentialMoves.push_back(cell);
                        }
                        cellLock.lock();
                        _targetCell = _gameState->getBoard().getCell(x,y);
                        cellLock.unlock();
                        
                    }
                }
            }
        }
        // If there are no available moves then end the game
        if(potentialMoves.size() < 1)  {
            _game->endGame(PieceTeam::White);
            return;
        }

        randomize(potentialMoves);
        
        int index = 0;
        std::this_thread::sleep_for(std::chrono::milliseconds(100 + (std::rand() % 900) ));
        int x = potentialMoves[index]->getX();
        int y = potentialMoves[index]->getY();

        cellLock.lock();
        _targetCell = _gameState->getBoard().getCell(x,y);
        cellLock.unlock();
        
        for(auto a: _game->getState()->getActionMatrix()->items(x,y)) {
            if(a->getPieceTeam() == PieceTeam::Black) {
                
                std::this_thread::sleep_for(std::chrono::milliseconds(700));
                _game->getState()->movePiece(a, _targetCell);
                _game->getState()->incrementTurn();
                lock.lock();
                _aiState = AIState::Waiting;
                return;
            }
        }


        lock.lock();
        _aiState = AIState::Waiting;
    });
    t.detach();
    
}

void AI::update() {
    if(_game->getState()->isGameOver())
        return;
    if(_aiState == AIState::Waiting && !_game->isPlayerTurn()!=0) {
        think();
    }
}