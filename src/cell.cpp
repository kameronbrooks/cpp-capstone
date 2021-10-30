#include "cell.h"

Cell::Cell() {
    _piece = nullptr;
    _x = -1;
    _y = -1;
    _black = false;
}
Cell::Cell(int x, int y) {
    _piece = nullptr;
    _x = x;
    _y = y;
    _black = (((_y % 2) + (_x % 2)) % 2) == 0;

}
Cell::Cell(const Cell& other) {
    _piece = other._piece;
    _black = other._black;
    _x = other._x;
    _y = other._y;
}

Cell& Cell::operator=(const Cell & cell) {
    _piece = cell._piece;
    _black = cell._black;
    _x = cell._x;
    _y = cell._y;

    return *this;
}

Cell& Cell::operator=(Cell&& cell) {
    if(&cell != this) {
        _piece = cell._piece;
        _black = cell._black;
        _x = cell._x;
        _y = cell._y;

        cell._piece = nullptr;
        cell._black = false;
        cell._x = -1;
        cell._y = -1;
    }

    return *this;
    
}

Piece* Cell::getPiece() {
    return _piece;
}
void Cell::setPiece(Piece* piece) {
    _piece = piece;
}

bool Cell::isOccupied() {
    return _piece != nullptr;
}

bool Cell::isWhite() {
    return !_black;
}
bool Cell::isBlack() {
    return _black;
}

 int Cell::getX() {
     return _x;
 }
int Cell::getY() {
    return _y;
}