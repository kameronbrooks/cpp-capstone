#ifndef PIECE_H
#define PIECE_H

#include "cell.h"
#include "piece_type.h"

class Piece {
private:
    int _timesMoved;
    bool _captured;
    Cell* _currentCell;
    PieceType* _pieceType;
public:
    Piece();
    Piece(const Piece& other);
    Piece(Piece&& other);
    Piece& operator=(const Piece& other);
    Piece& operator=(Piece&& other);

    int getTimesMoved();
    void MoveTo(Cell cell);

    Cell* GetCell();
    PieceType* GetPieceType();
    void SetPieceType(PieceType* type);
};

#endif