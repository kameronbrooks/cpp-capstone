#include "game_state.h"
#include "game.h"

GameState::GameState(Game*game) : _board() {
    std::cout << "GameState Contructor" << std::endl;
    _game = game;
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
    return ++_currentTurn;
}

Board& GameState::getBoard() {
    return _board;
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