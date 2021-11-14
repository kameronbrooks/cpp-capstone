#include "piece_knight.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"

int Knight::getId() {
    return 2;
}
void Knight::loadSprites(Renderer* renderer) {
    auto func = [renderer](std::string&& path){ return renderer->LoadSprite(std::move(path));};

    std::future<Sprite*> blk_future = std::async(std::launch::async, func, "../img/knight_black.png");
    std::future<Sprite*> white_future = std::async(std::launch::async, func, "../img/knight_white.png");

    _blackSprite = std::unique_ptr<Sprite>(blk_future.get());
    _whiteSprite = std::unique_ptr<Sprite>(white_future.get());
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
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {

        }
        else {
            gameState->addAction(piece, cell);
        }
        
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 1, -2);
    if(cell != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {

        }
        else {
            gameState->addAction(piece, cell);
        }
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), -1, -2);
    if(cell != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {

        }
        else {
            gameState->addAction(piece, cell);
        }
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 2, 1);
    if(cell != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {

        }
        else {
            gameState->addAction(piece, cell);
        }
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), -2, 1);
    if(cell != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {

        }
        else {
            gameState->addAction(piece, cell);
        }
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), 2, -1);
    if(cell != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {

        }
        else {
            gameState->addAction(piece, cell);
        }
    }
    cell = gameState->getBoard().getNeighbor(piece->getCell(), -2, -1);
    if(cell != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {

        }
        else {
            gameState->addAction(piece, cell);
        }
    }

}