#include "piece_queen.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"

int Queen::getId() {
    return QueenID;
}
void Queen::loadSprites(Renderer* renderer) {
    auto func = [renderer](std::string&& path){ return renderer->LoadSprite(std::move(path));};

    std::future<Sprite*> blk_future = std::async(std::launch::async, func, "../img/queen_black.png");
    std::future<Sprite*> white_future = std::async(std::launch::async, func, "../img/queen_white.png");

    _blackSprite = std::unique_ptr<Sprite>(blk_future.get());
    _whiteSprite = std::unique_ptr<Sprite>(white_future.get());
}

void Queen::onTurnStart(GameState* gameState, Piece* piece) {

}
void Queen::onTurnEnd(GameState* gameState, Piece* piece) {

}

void Queen::calculateMoves(Piece* piece, GameState* gameState ) {
    Cell* cell = piece->getCell();
    
    while((cell = gameState->getBoard().getNeighbor(cell, 1, 0)) != nullptr) {
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

    cell = piece->getCell();
    while((cell = gameState->getBoard().getNeighbor(cell, 0, -1)) != nullptr) {
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
    while((cell = gameState->getBoard().getNeighbor(cell, -1, 0)) != nullptr) {
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
    while((cell = gameState->getBoard().getNeighbor(cell, 0, 1)) != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {
            break;
        }
        gameState->addAction(piece, cell);
        if(cell->isOccupied()) {
            break;
        }
    }

    cell = piece->getCell();
    while((cell = gameState->getBoard().getNeighbor(cell, 1, 1)) != nullptr) {
        if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {
            break;
        }
        gameState->addAction(piece, cell);
        if(cell->isOccupied()) {
            break;
        }
    }
    
}