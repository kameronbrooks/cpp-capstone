#include "piece_pawn.h"
#include "renderer.h"
#include "sprite.h"

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

}