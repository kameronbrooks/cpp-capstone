#include "piece_rook.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"

int Rook::getId() {
    return 4;
}
void Rook::loadSprites(Renderer* renderer) {
    _blackSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/rook_black.png"));
    _whiteSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/rook_white.png"));
}

void Rook::onTurnStart(GameState* gameState, Piece* piece) {

}
void Rook::onTurnEnd(GameState* gameState, Piece* piece) {

}

void Rook::calculateMoves(Piece* piece, GameState* gameState ) {
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