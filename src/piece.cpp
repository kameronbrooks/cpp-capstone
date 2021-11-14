#include "piece.h"
#include "renderer.h"

Piece::Piece() {
    _pieceType = nullptr;
    _team = PieceTeam::White;
    _captured = false;
    _timesMoved = 0;
    _currentCell = nullptr;
}
Piece::Piece(PieceType* pieceType, PieceTeam team) {
    _pieceType = pieceType;
    _team = team;
    _captured = false;
    _timesMoved = 0;
    _currentCell = nullptr;
}
Piece::Piece(const Piece& other) {
    _pieceType = other._pieceType;
    _team = other._team;
    _captured = other._captured;
    _timesMoved = other._timesMoved;
    _currentCell = other._currentCell;
}
Piece::Piece(Piece&& other) {
    if(&other != this) {
        _pieceType = other._pieceType;
        _team = other._team;
        _captured = other._captured;
        _timesMoved = other._timesMoved;
        _currentCell = other._currentCell;

        other._pieceType = nullptr;
        other._team = PieceTeam::White;
        other._captured = false;
        other._timesMoved = 0;
        other._currentCell = nullptr;
    }
}
Piece& Piece::operator=(const Piece& other) {
    _pieceType = other._pieceType;
    _team = other._team;
    _captured = other._captured;
    _timesMoved = other._timesMoved;
    _currentCell = other._currentCell;

    return *this;
}
Piece& Piece::operator=(Piece&& other) {
    if(&other != this) {
        _pieceType = other._pieceType;
        _team = other._team;
        _captured = other._captured;
        _timesMoved = other._timesMoved;
        _currentCell = other._currentCell;

        other._pieceType = nullptr;
        other._team = PieceTeam::White;
        other._captured = false;
        other._timesMoved = 0;
        other._currentCell = nullptr;
    }
    return *this;
}

int Piece::getTimesMoved() {
    return _timesMoved;
}
void Piece::moveTo(Cell* cell) {
    if(_currentCell != nullptr) {
        _currentCell->setPiece(nullptr);
    }
    _currentCell = cell;
    ++_timesMoved;
}

void Piece::setCell(Cell* cell) {
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

    int centerX = tileX * tileSize + tileSize / 2;
    int centerY = tileY * tileSize + tileSize / 2;

    int pieceX = centerX - pieceSize / 2;
    int pieceY = centerY - pieceSize / 2;

    
    renderer->drawSprite(_pieceType->getSprite(_team), pieceX, pieceY, pieceSize, pieceSize);
    

}

void Piece::calculate(GameState* gameState) {
    _pieceType->calculateMoves(this, gameState);
}