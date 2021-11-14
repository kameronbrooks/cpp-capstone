#include "piece_bishop.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"

int Bishop::getId() {
    return 3;
}
void Bishop::loadSprites(Renderer* renderer) {
    auto func = [renderer](std::string&& path){ return renderer->LoadSprite(std::move(path));};

    std::future<Sprite*> blk_future = std::async(std::launch::async, func, "../img/bishop_black.png");
    std::future<Sprite*> white_future = std::async(std::launch::async, func, "../img/bishop_white.png");

    _blackSprite = std::unique_ptr<Sprite>(blk_future.get());
    _whiteSprite = std::unique_ptr<Sprite>(white_future.get());
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