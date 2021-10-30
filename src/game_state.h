#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <string>
#include <vector>
#include <memory>
#include "board.h"
#include "piece.h"

class Game;

class GameState {
private:
    Game* _game;
    int _currentTurn;
    Board _board;

    std::vector<std::unique_ptr<Piece>> _whitePieces;
    std::vector<std::unique_ptr<Piece>> _blackPieces;


public:
    GameState(Game*game);
    Game* getGame();
    int currentTurn();
    int currentPlayerIndex();
    int incrementTurn();

    Board& getBoard();

    void movePiece(Piece* piece, Cell* cell);
    void movePiece(Piece* piece, int x, int y);

    void removePiece(Piece* piece);
    void removePiece(int x, int y);


};

#endif