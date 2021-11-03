#include "game.h"
#include <iostream>
#include "globals.h"


Game::Game() : _renderer(800, 800), _input() {
    //Game::_instance = this;
    
    _input.setTarget(this);
    _selectedCell = nullptr;
    _hoverCell = nullptr;
 
}
Game::~Game() {
    
}

void Game::loadGameData() {
    std::cout << "Loading Game Data" << std::endl;
    try {
        _pawnType.loadSprites(&_renderer);
        _knightType.loadSprites(&_renderer);
        _bishopType.loadSprites(&_renderer);
        _rookType.loadSprites(&_renderer);
        _moveIcon = std::unique_ptr<Sprite>(_renderer.LoadSprite("../img/chess_icon_0.png"));
    }
    catch(...) {
         throw "Failed to load game data";
    }
    
    std::cout << "Game Data Loaded" << std::endl;
}

void Game::placePieces() {
    std::cout << "Placing Pieces" << std::endl;
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
    _state->calculateActions();
    while(_running) {
        auto now = std::chrono::high_resolution_clock::now();
         
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now -_lastTime).count() >= TARGET_FRAME_RATE_MILIS) {
            //std::cout << _accum << std::endl;
            _input.update();
            _input.pollEvents();
            _renderer.clear();
            render();
            _renderer.updateScreen();
            _lastTime = now;
        }
        
    }
}

bool Game::isPlayerTurn() {
    return _state->currentPlayerIndex() == 0;
}

void Game::onMouseDown(int x, int y) {

}
void Game::onMouseUp(int x, int y) {
    if(_state->currentPlayerIndex() != 0) return;

    if(_hoverCell != nullptr && _hoverCell->isOccupied() && _hoverCell->getPiece()->getPieceTeam() == PieceTeam::White) {
        _selectedCell = _hoverCell;
    }
    else if(_selectedCell != nullptr && _selectedCell->isOccupied()) {
        if(_hoverCell->isOccupied()) {
            _state->removePiece(_hoverCell->getPiece());
        }
        _state->movePiece(_selectedCell->getPiece(), _hoverCell);
        _state->incrementTurn();
        _selectedCell = nullptr;
    }
}
void Game::setMousePos(int x, int y) {
    int cellSize = _renderer.windowWidth() / BOARD_WIDTH;
    _hoverCell = _state->getBoard().getCell(x/cellSize, (_renderer.windowHeight() - y) / cellSize);
}
void Game::onExitApplication() {
    std::cout << "Closing application" << std::endl;
    _running = false;
}

void Game::drawMoves() {
    if(_selectedCell != nullptr && _selectedCell->isOccupied()) {
        int tileSize = _renderer.windowWidth() / BOARD_WIDTH;

        for(int y = 0; y < BOARD_HEIGHT; ++y) {
            for(int x = 0; x < BOARD_WIDTH; ++x) {
                if(_state->getActionMatrix()->contains(_selectedCell->getPiece(), x, y)) {
                    _renderer.drawSprite(_moveIcon.get(), x * tileSize, y * tileSize, tileSize, tileSize, _uiColor2);
                }

            }
        }
    }
    
}

void Game::render() {
    _state->getBoard().draw(&_renderer);

    int cellSize = _renderer.windowWidth() / BOARD_WIDTH;
    // draw pieces
    for(auto& piece: _state->getWhitePieces()) {
        piece->draw(&_renderer);
    }
    for(auto& piece: _state->getBlackPieces()) {
        piece->draw(&_renderer);
    }
    // draw current cell
    if(_hoverCell != nullptr) {
        _renderer.drawRect(_hoverCell->getX()*cellSize, _hoverCell->getY()*cellSize, cellSize, cellSize, _uiColor);
    }
    // draw selected cell
    if(_selectedCell != nullptr) {
        _renderer.drawRect(_selectedCell->getX()*cellSize, _selectedCell->getY()*cellSize, cellSize, cellSize, _uiColor);
    }
    
    // draw moves
    if(isPlayerTurn() && _selectedCell != nullptr) {
        drawMoves();
    }
    
    
}