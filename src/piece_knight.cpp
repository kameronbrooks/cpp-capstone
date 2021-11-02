#include "piece_knight.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"

int Knight::getId() {
    return 2;
}
void Knight::loadSprites(Renderer* renderer) {
    _blackSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/knight_black.png"));
    _whiteSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/knight_white.png"));
}

void Knight::onTurnStart(GameState* gameState, Piece* piece) {

}
void Knight::onTurnEnd(GameState* gameState, Piece* piece) {

}

void Knight::calculateMoves(Piece* piece, GameState* gameState ) {
    Cell* cell = gameState->getBoard().getNeighbor(piece->getCell(), 1, 2);
    if(cell != nullptr) {
        gameState->addAction(piece, cell);
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), -1, 2);
    if(cell != nullptr) {
        gameState->addAction(piece, cell);
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 1, -2);
    if(cell != nullptr) {
        gameState->addAction(piece, cell);
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), -1, -2);
    if(cell != nullptr) {
        gameState->addAction(piece, cell);
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 2, 1);
    if(cell != nullptr) {
        gameState->addAction(piece, cell);
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), -2, 1);
    if(cell != nullptr) {
        gameState->addAction(piece, cell);
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 2, -1);
    if(cell != nullptr) {
        gameState->addAction(piece, cell);
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), -2, -1);
    if(cell != nullptr) {
        gameState->addAction(piece, cell);
    }

}