#ifndef PIECE_QUEEN_H
#define PIECE_QUEEN_H
#include "piece_type.h"

class Queen : public PieceType {
public:
    int getId() override;
    void loadSprites(Renderer* renderer) override;

    void onTurnStart(GameState* gameState, Piece* piece) override;
    void onTurnEnd(GameState* gameState, Piece* piece) override;

    void calculateMoves(Piece* piece, GameState* gameState ) override;
};


#endif