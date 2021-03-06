#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include "board.h"
#include "piece.h"
#include "relation_matrix.h"

class Game;

class GameState {
private:
    Game* _game;
    int _currentTurn;
    int _winner;
    Board _board;
    RelationMatrix<Piece> _moveMatrix;

    std::vector<std::unique_ptr<Piece>> _whitePieces;
    std::vector<std::unique_ptr<Piece>> _blackPieces;

    std::mutex _turnMutex;
    std::mutex _piecesMutex;
    std::mutex _actionMutex;

    // how many actions are available for each team
    int _actionCount[2];


public:
    GameState(Game*game);
    Game* getGame();
    int currentTurn();
    int currentPlayerIndex();
    int incrementTurn();
    void startTurn();
    void endTurn();

    int winner() const;
    int& winner();

    bool isGameOver();

    Board& getBoard();

    void addPiece(PieceType* pieceType, PieceTeam team, int x, int y);

    std::vector<std::unique_ptr<Piece>>& getWhitePieces();
    std::vector<std::unique_ptr<Piece>>& getBlackPieces();

    void movePiece(Piece* piece, Cell* cell);
    void movePiece(Piece* piece, int x, int y);

    void removePiece(Piece* piece);
    void removePiece(int x, int y);

    void calculateActions();
    void clearActions();
    void addAction(Piece* piece, int x, int y);
    void addAction(Piece* piece, Cell* cell);

    RelationMatrix<Piece>* getActionMatrix();

    bool isCellGuarded(Cell* cell, PieceTeam guardingTeam);

    int availableActionCount(PieceTeam team);

};

#endif