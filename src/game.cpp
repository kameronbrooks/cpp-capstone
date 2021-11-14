#include "game.h"
#include <iostream>
#include <exception>
#include "globals.h"


Game::Game() : _renderer(800, 800), _input(), _ai(this) {
    //Game::_instance = this;
    
    _input.setTarget(this);
    _selectedCell = nullptr;
    _hoverCell = nullptr;
 
}
Game::~Game() {
    
}

void Game::loadGameData() {
    std::cout << "Loading Game Data" << std::endl;
    std::exception_ptr except = nullptr;
    auto func_load_sprite = [this](std::string&& path){ 
        return _renderer.LoadSprite(std::move(path));
    };
    auto func_load_piece_sprites = [this, &except](PieceType* piece) {
        try {
            piece->loadSprites(&_renderer);
        }
        catch(...) {
            except = std::current_exception();
        }
    };
    
    try {
        // Start all threads
        std::thread pawn_thread(func_load_piece_sprites, &_pawnType);
        std::thread knight_thread(func_load_piece_sprites, &_knightType);
        std::thread bishop_thread(func_load_piece_sprites, &_bishopType);
        std::thread rook_thread(func_load_piece_sprites, &_rookType);
        std::thread queen_thread(func_load_piece_sprites, &_queenType);
        std::future<Sprite*> move_icon_sprite_ftr = std::async(std::launch::async, func_load_sprite, "../img/chess_icon_0.png");

        // Join all threads
        pawn_thread.join();
        knight_thread.join();
        bishop_thread.join();
        rook_thread.join();
        queen_thread.join();
        _moveIcon = std::unique_ptr<Sprite>(move_icon_sprite_ftr.get());

        // Handle exceptions in all threads
        if(except != nullptr) {
            std::rethrow_exception(except);
        }
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
    _state->addPiece(&_queenType, PieceTeam::White, 4,0);
    
    for(int i = 0; i < 8; ++i) {
        _state->addPiece(&_pawnType, PieceTeam::Black, i,6);
    }
    _state->addPiece(&_knightType, PieceTeam::Black, 1,7);
    _state->addPiece(&_knightType, PieceTeam::Black, 6,7);
    _state->addPiece(&_bishopType, PieceTeam::Black, 2,7);
    _state->addPiece(&_bishopType, PieceTeam::Black, 5,7);
    _state->addPiece(&_rookType, PieceTeam::Black, 0,7);
    _state->addPiece(&_rookType, PieceTeam::Black, 7,7);
    _state->addPiece(&_queenType, PieceTeam::Black, 3,7);

    std::cout << "Done placing pieces" << std::endl;
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
            _input.update();
            _input.pollEvents();
            _ai.update();
            _renderer.clear();
            render();
            _renderer.updateScreen();
            _lastTime = now;
        }
        
    }
}

void Game::startTurn() {
    for(auto& piece: _state->getWhitePieces()) {
        piece->getPieceType()->onTurnStart(_state.get(), piece.get());
    }
    for(auto& piece: _state->getBlackPieces()) {
        piece->getPieceType()->onTurnStart(_state.get(), piece.get());
    }
}
void Game::endTurn() {
    for(auto& piece: _state->getWhitePieces()) {
        piece->getPieceType()->onTurnEnd(_state.get(), piece.get());
    }
    for(auto& piece: _state->getBlackPieces()) {
        piece->getPieceType()->onTurnEnd(_state.get(), piece.get());
    }
}

void Game::endGame(PieceTeam winner) {
    
}

GameState* Game::getState() {
    return _state.get();
}

bool Game::isPlayerTurn() {
    return _state->currentPlayerIndex() == 0;
}

void Game::onMouseDown(int x, int y) {

}
void Game::onMouseUp(int x, int y) {
    if(!isPlayerTurn()) return;

    if(_hoverCell != nullptr && _hoverCell->isOccupied() && _hoverCell->getPiece()->getPieceTeam() == PieceTeam::White) {
        _selectedCell = _hoverCell;
    }
    else if(_selectedCell != nullptr && _selectedCell->isOccupied()) {
        if(_state.get()->getActionMatrix()->contains(_selectedCell->getPiece(), _hoverCell->getX(), _hoverCell->getY())) {
            if(_hoverCell->isOccupied()) {
                _state->removePiece(_hoverCell->getPiece());
            }
            _state->movePiece(_selectedCell->getPiece(), _hoverCell);
            _state->incrementTurn();
            _selectedCell = nullptr;
        }
        
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

    if(_ai.getState() == AIState::Calculating && _ai.hasTargetCell()) {
        Cell* aitarg = _ai.getTargetCell();
        _renderer.drawRect(aitarg ->getX()*cellSize, aitarg ->getY()*cellSize, cellSize, cellSize, _aiColor);
    }
    
    // draw moves
    if(isPlayerTurn() && _selectedCell != nullptr) {
        drawMoves();
    }
    
    
}

PieceType* Game::getPieceType(int id) {
    switch(id) {
        case PawnID:
            return &_pawnType;
        case KnightID:
            return &_knightType;
        case BishopID:
            return &_bishopType;
        case RookID:
            return &_rookType;
        case QueenID:
            return &_queenType;
        case KingID:
            return nullptr;
        default:
            return nullptr;
    }
}