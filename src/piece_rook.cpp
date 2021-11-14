#include "piece_rook.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"

int Rook::getId() {
    return 4;
}
void Rook::loadSprites(Renderer* renderer) {
    auto func = [renderer](std::string&& path){ return renderer->LoadSprite(std::move(path));};

    std::future<Sprite*> blk_future = std::async(std::launch::async, func, "../img/rook_black.png");
    std::future<Sprite*> white_future = std::async(std::launch::async, func, "../img/rook_white.png");

    _blackSprite = std::unique_ptr<Sprite>(blk_future.get());
    _whiteSprite = std::unique_ptr<Sprite>(white_future.get());
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