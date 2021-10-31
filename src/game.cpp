#include "game.h"
#include <iostream>

Game::Game() : _renderer(800, 800), _input() {
    //Game::_instance = this;
    
    _input.setTarget(this);
}
Game::~Game() {
    
}

void Game::loadGameData() {
    _pawnType.loadSprites(&_renderer);
}

void Game::placePieces() {
    for(int i = 0; i < 8; ++i) {
        _state->addPiece(&_pawnType, PieceTeam::White, i,1);
    }
    

    for(int i = 0; i < 8; ++i) {
        _state->addPiece(&_pawnType, PieceTeam::Black, i,6);
    }
}


void Game::startGame() {
    loadGameData();
    
    _running = true;
    _state = std::make_unique<GameState>(this);

    placePieces();

    while(_running) {
        _input.pollEvents();
        _renderer.clear();
        render();
        _renderer.updateScreen();
    }
    
}

void Game::onMouseDown(int x, int y) {

}
void Game::onMouseUp(int x, int y) {
    std::cout << "Mouse Down: " << x << " " << y << std::endl; 
}
void Game::onMouseMove(int x, int y) {

}
void Game::onExitApplication() {
    std::cout << "Closing application" << std::endl;
    _running = false;
}

void Game::render() {
    _state->getBoard().draw(&_renderer);

    for(auto& piece: _state->getWhitePieces()) {
        piece->draw(&_renderer);
    }
    for(auto& piece: _state->getBlackPieces()) {
        piece->draw(&_renderer);
    }
}