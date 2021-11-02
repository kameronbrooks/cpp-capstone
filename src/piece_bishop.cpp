#include "piece_bishop.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"

int Bishop::getId() {
    return 3;
}
void Bishop::loadSprites(Renderer* renderer) {
    _blackSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/bishop_black.png"));
    _whiteSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/bishop_white.png"));
}

void Bishop::onTurnStart(GameState* gameState, Piece* piece) {

}
void Bishop::onTurnEnd(GameState* gameState, Piece* piece) {

}

void Bishop::calculateMoves(Piece* piece, GameState* gameState ) {
    Cell* cell = piece->getCell();

    while((cell = gameState->getBoard().getNeighbor(cell, 1, 1)) != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {
            break;
        }
        gameState->addAction(piece, cell);
        if(cell->isOccupied()) {
            break;
        }
    }

    cell = piece->getCell();
    while((cell = gameState->getBoard().getNeighbor(cell, -1, 1)) != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {
            break;
        }
        gameState->addAction(piece, cell);
        if(cell->isOccupied()) {
            break;
        }
    }

    cell = piece->getCell();
    while((cell = gameState->getBoard().getNeighbor(cell, -1, -1)) != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {
            break;
        }
        gameState->addAction(piece, cell);
        if(cell->isOccupied()) {
            break;
        }
    }

    cell = piece->getCell();
    while((cell = gameState->getBoard().getNeighbor(cell, 1, -1)) != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {
            break;
        }
        gameState->addAction(piece, cell);
        if(cell->isOccupied()) {
            break;
        }
    }
}