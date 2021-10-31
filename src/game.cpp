#include "game.h"
#include <iostream>

Game::Game() : _renderer(800, 800), _input() {
    //Game::_instance = this;
    
    _input.setTarget(this);
    _selectedCell = nullptr;
    _hoverCell = nullptr;

    _uiColor = Color(100,255,100,100);
}
Game::~Game() {
    
}

void Game::loadGameData() {
    _pawnType.loadSprites(&_renderer);
    _knightType.loadSprites(&_renderer);
    _bishopType.loadSprites(&_renderer);
    _rookType.loadSprites(&_renderer);
}

void Game::placePieces() {
    for(int i = 0; i < 8; ++i) {
        _state->addPiece(&_pawnType, PieceTeam::White, i,1);
    }
    _state->addPiece(&_knightType, PieceTeam::White, 1,0);
    _state->addPiece(&_knightType, PieceTeam::White, 6,0);
    _state->addPiece(&_bishopType, PieceTeam::White, 2,0);
    _state->addPiece(&_bishopType, PieceTeam::White, 5,0);
    _state->addPiece(&_rookType, PieceTeam::White, 0,0);
    _state->addPiece(&_rookType, PieceTeam::White, 7,0);
    

    for(int i = 0; i < 8; ++i) {
        _state->addPiece(&_pawnType, PieceTeam::Black, i,6);
    }
    _state->addPiece(&_knightType, PieceTeam::Black, 1,7);
    _state->addPiece(&_knightType, PieceTeam::Black, 6,7);
    _state->addPiece(&_bishopType, PieceTeam::Black, 2,7);
    _state->addPiece(&_bishopType, PieceTeam::Black, 5,7);
    _state->addPiece(&_rookType, PieceTeam::Black, 0,7);
    _state->addPiece(&_rookType, PieceTeam::Black, 7,7);
}


void Game::startGame() {
    loadGameData();
    
    _running = true;
    _state = std::make_unique<GameState>(this);
    _accum = 0;
    _lastTime = std::chrono::high_resolution_clock::now();
    placePieces();

    while(_running) {
        auto now = std::chrono::high_resolution_clock::now();
        _accum += std::chrono::duration_cast<std::chrono::milliseconds>(now-_lastTime).count();
        _input.pollEvents();
        
        if(_accum >= TARGET_FRAME_RATE_MILIS) {
            _renderer.clear();
            render();
            _renderer.updateScreen();
            _accum -= TARGET_FRAME_RATE_MILIS;
        }
        _lastTime = now;
        
    }
    
}

void Game::onMouseDown(int x, int y) {

}
void Game::onMouseUp(int x, int y) {
    if(_hoverCell != nullptr && _hoverCell->isOccupied() && _hoverCell->getPiece()->getPieceTeam() == PieceTeam::White) {
        _selectedCell = _hoverCell;
    }
}
void Game::onMouseMove(int x, int y) {
    int cellSize = _renderer.windowWidth() / BOARD_WIDTH;
    _hoverCell = _state->getBoard().getCell(x/cellSize, (_renderer.windowHeight() - y) / cellSize);
}
void Game::onExitApplication() {
    std::cout << "Closing application" << std::endl;
    _running = false;
}

void Game::render() {
    _state->getBoard().draw(&_renderer);

    int cellSize = _renderer.windowWidth() / BOARD_WIDTH;

    for(auto& piece: _state->getWhitePieces()) {
        piece->draw(&_renderer);
    }
    for(auto& piece: _state->getBlackPieces()) {
        piece->draw(&_renderer);
    }

    if(_hoverCell != nullptr) {
        _renderer.drawRect(_hoverCell->getX()*cellSize, _hoverCell->getY()*cellSize, cellSize, cellSize, _uiColor);
    }

    if(_selectedCell != nullptr) {
        _renderer.drawRect(_selectedCell->getX()*cellSize, _selectedCell->getY()*cellSize, cellSize, cellSize, _uiColor);
    }

    
}