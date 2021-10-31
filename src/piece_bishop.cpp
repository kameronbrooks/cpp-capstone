#include "piece_bishop.h"
#include "renderer.h"
#include "sprite.h"

int Bishop::getId() {
    return 3;
}
void Bishop::loadSprites(Renderer* renderer) {
    _blackSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/bishop_black.png"));
    _whiteSprite = std::unique_ptr<Sprite>(renderer->LoadSprite("../img/bishop_white.png"));
}

void Bishop::onTurnStart(GameState* gameState, Piece* piece) {

}
void Bishop::onTurnEnd(GameState* gameState, Piece* piece) {

}

void Bishop::calculateMoves(Piece* piece, GameState* gameState ) {

}