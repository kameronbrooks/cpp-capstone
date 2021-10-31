#include "piece_rook.h"
#include "renderer.h"
#include "sprite.h"

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

}