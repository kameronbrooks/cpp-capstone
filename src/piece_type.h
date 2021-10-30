#ifndef PIECE_TYPE_H
#define PIECE_TYPE_H
#include <string>
#include "sprite.h"
#include "globals.h"

class Game;
class Piece;
class GameState;


class PieceType {
protected:
    std::unique_ptr<Sprite> _whiteSprite;
    std::unique_ptr<Sprite> _blackSprite;
    std::string _name;
public:

    std::string getName();
    virtual int getId()=0;

    virtual void onTurnStart(GameState* gameState, Piece* piece);
    virtual void onTurnEnd(GameState* gameState, Piece* piece);

    virtual void calculateMoves(Piece* piece, GameState* gameState )=0;

    Sprite* getSprite(PieceTeam team);


};

#endif