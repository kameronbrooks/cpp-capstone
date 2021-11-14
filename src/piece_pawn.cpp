#include "piece_pawn.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"
#include "game.h"


int Pawn::getId() {
    return PawnID;
}
void Pawn::loadSprites(Renderer* renderer) {
    auto func = [renderer](std::string&& path){ return renderer->LoadSprite(std::move(path));};

    std::future<Sprite*> blk_future = std::async(std::launch::async, func, "../img/pawn_black.png");
    std::future<Sprite*> white_future = std::async(std::launch::async, func, "../img/pawn_white.png");

    _blackSprite = std::unique_ptr<Sprite>(blk_future.get());
    _whiteSprite = std::unique_ptr<Sprite>(white_future.get());
}

void Pawn::onTurnStart(GameState* gameState, Piece* piece) {

}
void Pawn::onTurnEnd(GameState* gameState, Piece* piece) {
    if(piece->getPieceTeam() == PieceTeam::Black && piece->getCell()->getY() == 0) {
        piece->setPieceType(gameState->getGame()->getPieceType(QueenID));
    }
    else if(piece->getPieceTeam() == PieceTeam::White && piece->getCell()->getY() == BOARD_HEIGHT-1) {
        piece->setPieceType(gameState->getGame()->getPieceType(QueenID));
    }
}

void Pawn::calculateMoves(Piece* piece, GameState* gameState ) {
    int dirMult = (piece->getPieceTeam() == PieceTeam::White) ? 1 : -1;
    Cell* cell = gameState->getBoard().getNeighbor(piece->getCell(), 0, 1*dirMult);
    // Move 0
    if(cell != nullptr && !cell->isOccupied()) {
        gameState->addAction(piece, cell);
    }
    // Move 1
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 1, 1*dirMult);
    if(cell != nullptr && cell->isOccupied() && cell->getPiece()->getPieceTeam() != piece->getPieceTeam()) {
        gameState->addAction(piece, cell);
    }
    // Move 2
    cell = gameState->getBoard().getNeighbor(piece->getCell(), -1, 1*dirMult);
    if(cell != nullptr && cell->isOccupied() && cell->getPiece()->getPieceTeam() != piece->getPieceTeam()) {
        gameState->addAction(piece, cell);
    }
    // Move 3
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 0, 2*dirMult);
    if(cell != nullptr && piece->getTimesMoved() < 1 && !cell->isOccupied()) {
        gameState->addAction(piece, cell);
    }

} 