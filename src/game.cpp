#include "game.h"
#include <iostream>

Game::Game() : _renderer(640, 480), _input() {
    //Game::_instance = this;

    _input.setTarget(this);
}
Game::~Game() {
    
}


void Game::StartGame() {
    _running = true;
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

}
void Game::onMouseMove(int x, int y) {

}
void Game::onExitApplication() {
    std::cout << "Closing application" << std::endl;
    _running = false;
}

void Game::render() {

}