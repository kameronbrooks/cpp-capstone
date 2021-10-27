#ifndef PIECE_TYPE_H
#define PIECE_TYPE_H
#include <string>

class Game;
class Piece;
class GameState;

class PieceType {
public:

private:
    std::string getName();
    int getId();

    void OnTurnStart(GameState* gameState, Piece* piece);
    void OnTurnEnd(GameState* gameState, Piece* piece);

    void CalculateMoves(Piece* piece);


};

#endif