#ifndef CELL_H
#define CELL_H

#include "globals.h"

class Piece;

class Cell {
private:
    Piece* _piece;
    bool _black;
    int _x, _y;
public:
    Cell();
    Cell(int x, int y);
    Cell(const Cell& other);

    Cell& operator=(const Cell & cell);
    Cell& operator=(Cell&& cell);

    Piece* getPiece();
    void setPiece(Piece* piece);

    bool isOccupied();

    bool isWhite();
    bool isBlack();

    int getX();
    int getY();

};

#endif