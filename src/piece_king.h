#ifndef PIECE_KING_H
#define PIECE_KING_H
#include "piece_type.h"

class King : public PieceType {
public:
    int getId() override;
    void loadSprites(Renderer* renderer) override;

    void onTurnStart(GameState* gameState, Piece* piece) override;
    void onTurnEnd(GameState* gameState, Piece* piece) override;
    void onCaptured(GameState* gameState, Piece* piece) override;

    void calculateMoves(Piece* piece, GameState* gameState ) override;
};


#endif