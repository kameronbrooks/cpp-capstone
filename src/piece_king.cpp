#include "piece_king.h"
#include "renderer.h"
#include "sprite.h"
#include "cell.h"
#include "game_state.h"
#include "game.h"


int King::getId() {
    return KingID;
}
void King::loadSprites(Renderer* renderer) {
    auto func = [renderer](std::string&& path){ return renderer->LoadSprite(std::move(path));};

    std::future<Sprite*> blk_future = std::async(std::launch::async, func, "../img/king_black.png");
    std::future<Sprite*> white_future = std::async(std::launch::async, func, "../img/king_white.png");

    _blackSprite = std::unique_ptr<Sprite>(blk_future.get());
    _whiteSprite = std::unique_ptr<Sprite>(white_future.get());
}

void King::onTurnStart(GameState* gameState, Piece* piece) {

}
void King::onTurnEnd(GameState* gameState, Piece* piece) {

}
void King::onCaptured(GameState* gameState, Piece* piece) {
    gameState->getGame()->endGame(piece->getPieceTeam() == PieceTeam::White ? PieceTeam::Black : PieceTeam::White);
}

void King::calculateMoves(Piece* piece, GameState* gameState ) {
    Cell* cell = piece->getCell();

    
    for(int x = -1; x <= 1; ++x) {
        for(int y = -1; y <= 1; ++y) {
            if(x == 0 && y == 0)
                continue;

            if((cell = gameState->getBoard().getNeighbor(piece->getCell(), x, y)) != nullptr) {
                if(gameState->isCellGuarded(cell, piece->getPieceTeam() == PieceTeam::Black ? PieceTeam::White : PieceTeam::Black))
                    continue;

                if(cell->isOccupied() && cell->getPiece()->getPieceTeam() == piece->getPieceTeam()) {

                }
                else {
                    gameState->addAction(piece, cell);
                }
            }
        }
    }

} 