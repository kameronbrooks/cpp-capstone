#include "game.h"
#include <iostream>

Game::Game() : _renderer(800, 800), _input() {
    //Game::_instance = this;
    
    _input.setTarget(this);
}
Game::~Game() {
    
}


void Game::StartGame() {
    _running = true;
    _state = std::make_unique<GameState>(this);
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
}