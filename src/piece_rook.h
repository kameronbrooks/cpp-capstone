#ifndef PIECE_ROOK_H
#define PIECE_ROOK_H
#include "piece_type.h"

class Rook : public PieceType {
public:
    int getId() override;
    void loadSprites(Renderer* renderer) override;

    void onTurnStart(GameState* gameState, Piece* piece) override;
    void onTurnEnd(GameState* gameState, Piece* piece) override;

    void calculateMoves(Piece* piece, GameState* gameState ) override;
};


#endif