#include "piece_type.h"

std::string PieceType::getName() {
    return _name;
}

void PieceType::onTurnStart(GameState* gameState, Piece* piece) {

}
void PieceType::onTurnEnd(GameState* gameState, Piece* piece) {

}


Sprite* PieceType::getSprite(PieceTeam team) {
    if(team == PieceTeam::Black) {
        return _blackSprite.get();
    }
    else {
        return _whiteSprite.get();
    }
}