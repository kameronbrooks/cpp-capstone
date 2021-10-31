#ifndef PIECE_H
#define PIECE_H

#include "cell.h"
#include "piece_type.h"
#include "globals.h"

class Renderer;


class Piece {
private:
    int _timesMoved;
    bool _captured;
    Cell* _currentCell;
    PieceType* _pieceType;
    PieceTeam _team;
public:
    Piece();
    Piece(PieceType* pieceType, PieceTeam team);
    Piece(const Piece& other);
    Piece(Piece&& other);
    Piece& operator=(const Piece& other);
    Piece& operator=(Piece&& other);

    int getTimesMoved();
    void moveTo(Cell* cell);

    void setCell(Cell* cell);
    Cell* getCell();
    PieceType* getPieceType();
    void setPieceType(PieceType* type);
    PieceTeam getPieceTeam();
    void setPieceTeam(PieceTeam team);

    void draw(Renderer* renderer);

    
};

#endif