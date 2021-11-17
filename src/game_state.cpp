#include "game_state.h"
#include "game.h"
#include "piece.h"

GameState::GameState(Game*game) : _board() {
    std::cout << "GameState Contructor" << std::endl;
    _game = game;
    _currentTurn = 0;
    _winner = -1;
}
Game* GameState::getGame() {
    return _game;
}

int GameState::winner() const {
    return _winner;
}
int& GameState::winner() {
    return _winner;
}

bool GameState::isGameOver() {
    return _winner != -1;
}

int GameState::currentTurn() {
    std::lock_guard<std::mutex> lock(_turnMutex);
    return _currentTurn;
}
int GameState::currentPlayerIndex() {
    std::lock_guard<std::mutex> lock(_turnMutex);
    return _currentTurn % 2;
}
int GameState::incrementTurn() {
    clearActions();
    calculateActions();
    if(_actionCount[0] == 0)
        _game->endGame(PieceTeam::Black);
    if(_actionCount[1] == 0)
        _game->endGame(PieceTeam::White);
    endTurn();
    std::unique_lock<std::mutex> lock(_turnMutex);
    ++_currentTurn;
    lock.unlock();
    startTurn();
    return _currentTurn;
}

void GameState::startTurn() {
    for(auto& piece: _whitePieces) {
        piece->getPieceType()->onTurnStart(this, piece.get());
    }
    for(auto& piece: _blackPieces) {
        piece->getPieceType()->onTurnStart(this, piece.get());
    }
}
void GameState::endTurn() {
    for(auto& piece: _whitePieces) {
        piece->getPieceType()->onTurnEnd(this, piece.get());
    }
    for(auto& piece: _blackPieces) {
        piece->getPieceType()->onTurnEnd(this, piece.get());
    }
}

Board& GameState::getBoard() {
    return _board;
}

void GameState::addPiece(PieceType* pieceType, PieceTeam team, int x, int y) {
    Piece* newPiece = new Piece(pieceType, team);
    Cell* cell = _board.getCell(x,y);

    newPiece->setCell(cell);
    cell->setPiece(newPiece);

    std::lock_guard<std::mutex> lock(_piecesMutex);
    if(team == PieceTeam::Black) {      
        _blackPieces.push_back(std::unique_ptr<Piece>(newPiece));
    }
    else {
        _whitePieces.push_back(std::unique_ptr<Piece>(newPiece));
    }
    
}

std::vector<std::unique_ptr<Piece>>& GameState::getWhitePieces() {
    std::lock_guard<std::mutex> lock(_piecesMutex);
    return _whitePieces;
}
std::vector<std::unique_ptr<Piece>>& GameState::getBlackPieces() {
    std::lock_guard<std::mutex> lock(_piecesMutex);
    return _blackPieces;
}

void GameState::movePiece(Piece* piece, Cell* cell) {
    
    if(cell->isOccupied()) {
        removePiece(cell->getPiece());
    }
    std::lock_guard<std::mutex> lock(_piecesMutex);
    cell->setPiece(piece);
    piece->moveTo(cell);
}
void GameState::movePiece(Piece* piece, int x, int y) {
    movePiece(piece, _board.getCell(x,y));
}

void GameState::removePiece(Piece* piece) {

    std::lock_guard<std::mutex> lock(_piecesMutex);
    piece->getPieceType()->onCaptured(this, piece);
    if(piece->getPieceTeam() == PieceTeam::White) {
        auto iter = _whitePieces.begin();
        while(iter != _whitePieces.end()) {
            if(iter->get() == piece) {
                _whitePieces.erase(iter);
                return;
            }
            iter++;
        }
    } else {
        auto iter = _blackPieces.begin();
        while(iter != _blackPieces.end()) {
            if(iter->get() == piece) {
                _blackPieces.erase(iter);
                return;
            }
            iter++;
        }
    }

}
void GameState::removePiece(int x, int y) {
    Piece* p = _board.getCell(x,y)->getPiece();
    removePiece(p);
}

void GameState::clearActions() {
    std::lock_guard<std::mutex> lock(_actionMutex);
    _moveMatrix.clear();
    _actionCount[0] = _actionCount[1] = 0;
}
void GameState::addAction(Piece* piece, int x, int y) {
    std::lock_guard<std::mutex> lock(_actionMutex);
    _moveMatrix.add(piece, x, y);
    ++_actionCount[(int)piece->getPieceTeam()];
}
void GameState::addAction(Piece* piece, Cell* cell) {
    addAction(piece, cell->getX(), cell->getY());
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
    std::lock_guard<std::mutex> lock(_actionMutex);
    return &_moveMatrix;
}

bool GameState::isCellGuarded(Cell* cell, PieceTeam guardingTeam) {
    for(auto piece: _moveMatrix.items(cell->getX(), cell->getY())) {
        if(piece->getPieceTeam() == guardingTeam) {
            return true;
        }
    }
    return false;
}

int GameState::availableActionCount(PieceTeam team) {
    return _actionCount[(int)team];
}