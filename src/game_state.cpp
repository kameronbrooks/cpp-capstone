#include "game_state.h"
#include "game.h"

GameState::GameState(Game*game) : _board() {
    std::cout << "GameState Contructor" << std::endl;
    _game = game;
    _currentTurn = 0;
}
Game* GameState::getGame() {
    return _game;
}
int GameState::currentTurn() {
    return _currentTurn;
}
int GameState::currentPlayerIndex() {
    return _currentTurn % 2;
}
int GameState::incrementTurn() {
    clearActions();
    calculateActions();
    return ++_currentTurn;
}

Board& GameState::getBoard() {
    return _board;
}

void GameState::addPiece(PieceType* pieceType, PieceTeam team, int x, int y) {
    Piece* newPiece = new Piece(pieceType, team);
    Cell* cell = _board.getCell(x,y);

    newPiece->setCell(cell);
    cell->setPiece(newPiece);

    if(team == PieceTeam::Black) {      
        _blackPieces.push_back(std::unique_ptr<Piece>(newPiece));
    }
    else {
        _whitePieces.push_back(std::unique_ptr<Piece>(newPiece));
    }
    
}

std::vector<std::unique_ptr<Piece>>& GameState::getWhitePieces() {
    return _whitePieces;
}
std::vector<std::unique_ptr<Piece>>& GameState::getBlackPieces() {
    return _blackPieces;
}

void GameState::movePiece(Piece* piece, Cell* cell) {
    if(cell->isOccupied()) {
        removePiece(cell->getPiece());
    }
    cell->setPiece(piece);
    piece->moveTo(cell);
}
void GameState::movePiece(Piece* piece, int x, int y) {
    movePiece(piece, _board.getCell(x,y));
}

void GameState::removePiece(Piece* piece) {

}
void GameState::removePiece(int x, int y) {

}

void GameState::clearActions() {
    _moveMatrix.clear();
}
void GameState::addAction(Piece* piece, int x, int y) {
    _moveMatrix.add(piece, x, y);
}
void GameState::addAction(Piece* piece, Cell* cell) {
    _moveMatrix.add(piece, cell->getX(), cell->getY());
}

void GameState::calculateActions() {
    for(auto& piece:_whitePieces) {
        piece->calculate(this);
    }
    for(auto& piece:_blackPieces) {
        piece->calculate(this);
    }
}

RelationMatrix<Piece>* GameState::getActionMatrix() {
    return &_moveMatrix;
}