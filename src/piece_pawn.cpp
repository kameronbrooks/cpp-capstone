#include "piece_pawn.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"

int Pawn::getId() {
    return 1;
}
void Pawn::loadSprites(Renderer* renderer) {
    _blackSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/pawn_black.png"));
    _whiteSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/pawn_white.png"));
}

void Pawn::onTurnStart(GameState* gameState, Piece* piece) {

}
void Pawn::onTurnEnd(GameState* gameState, Piece* piece) {

}

void Pawn::calculateMoves(Piece* piece, GameState* gameState ) {
    Cell* cell = gameState->getBoard().getNeighbor(piece->getCell(), 0, 1);
    // Move 0
    if(cell != nullptr && !cell->isOccupied()) {
        gameState->addAction(piece, cell);
    }
    // Move 1
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 1, 1);
    if(cell != nullptr && cell->isOccupied() && cell->getPiece()->getPieceTeam() != piece->getPieceTeam()) {
        gameState->addAction(piece, cell);
    }
    // Move 2
    cell = gameState->getBoard().getNeighbor(piece->getCell(), -1, 1);
    if(cell != nullptr && cell->isOccupied() && cell->getPiece()->getPieceTeam() != piece->getPieceTeam()) {
        gameState->addAction(piece, cell);
    }
    // Move 3
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 0, 2);
    if(cell != nullptr && piece->getTimesMoved() < 1 && !cell->isOccupied()) {
        gameState->addAction(piece, cell);
    }

} 