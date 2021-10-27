#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <string>
#include <vector>
#include <memory>
#include "board.h"
#include "piece.h"

class Game;

class GameState {
public:
    Game* _game;
    int _currentTurn;
    Board _board;

    std::vector<std::unique_ptr<Piece>> _whitePieces;
    std::vector<std::unique_ptr<Piece>> _blackPieces;


private:
    Game* getGame();
    int currentTurn();
    int currentPlayerIndex();
    int incrementTurn();

    Board& getBoard();

    void MovePiece(Piece* piece, Cell* cell);
    void MovePiece(Piece* piece, int x, int y);

    void RemovePiece(Piece* piece);
    void RemovePiece(int x, int y);


};

#endif