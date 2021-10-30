#include "piece.h"
#include "renderer.h"

Piece::Piece() {

}
Piece::Piece(PieceType* pieceType, PieceTeam team) {

}
Piece::Piece(const Piece& other) {

}
Piece::Piece(Piece&& other) {

}
Piece& Piece::operator=(const Piece& other) {
    return *this;
}
Piece& Piece::operator=(Piece&& other) {
    return *this;
}

int Piece::getTimesMoved() {
    return _timesMoved;
}
void Piece::moveTo(Cell* cell) {
    _currentCell = cell;
}

Cell* Piece::getCell() {
    return _currentCell;
}
PieceType* Piece::getPieceType() {
    return _pieceType;
}
void Piece::setPieceType(PieceType* type) {
    _pieceType = type;
}
PieceTeam Piece::getPieceTeam() {
    return _team;
}
void Piece::setPieceTeam(PieceTeam team) {
    _team = team;
}

void Piece::draw(Renderer* renderer) {
    if(_pieceType == nullptr) return;
    int tileX = _currentCell->getX();
    int tileY = _currentCell->getY();
    int tileSize = renderer->windowWidth() / BOARD_WIDTH;
    int pieceSize = (int)((float)tileSize * 0.75);

    int centerX = tileX + tileSize / 2;
    int centerY = tileY + tileSize / 2;

    int pieceX = centerX - pieceSize / 2;
    int pieceY = centerY - pieceSize / 2;

    renderer->drawSprite(_pieceType->getSprite(_team), pieceX, pieceY, pieceSize, pieceSize);
    

}