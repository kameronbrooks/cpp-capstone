#ifndef CELL_H
#define CELL_H

class Piece;

class Cell {
private:
    Piece* _piece;
    bool _black;
public:
    Cell();
    Cell(int x, int y);
    Cell(const Cell& other);

    Piece* getPiece();
    void setPiece(Piece* piece);

    bool isOccupied();

    bool isWhite();
    bool isBlack();

};

#endif