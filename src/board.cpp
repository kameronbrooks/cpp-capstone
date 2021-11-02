#include "board.h"
#include "renderer.h"

Board::Board() {
    std::cout << "Board Constructor" << std::endl;
    for(int y = 0; y < BOARD_HEIGHT; ++y) {
        for(int x = 0; x < BOARD_WIDTH; ++x) {
            cells[x][y] = Cell(x,y);
        }
    }
}
Cell* Board::getCell(int x, int y) {
    if(x < 0 || x >= BOARD_WIDTH || y < 0 || y >= BOARD_HEIGHT) 
        return nullptr;

    return &cells[x][y];
}

Cell* Board::getNeighbor(Cell* current, int xOffset, int yOffset) {
    int x = current->getX()+xOffset;
    int y = current->getY()+yOffset;
    if(x < 0 || x >= BOARD_WIDTH || y < 0 || y >= BOARD_HEIGHT) 
        return nullptr;

    return &cells[x][y];
}

void Board::draw(Renderer* renderer) {
    int tileSize = renderer->windowWidth() / BOARD_WIDTH;
    Color whiteColor(220,220,200,255);
    Color blackColor(100,100,100,255);
    for(int y = 0; y < BOARD_HEIGHT; ++y) {
        for(int x = 0; x < BOARD_WIDTH; ++x) {
            renderer->drawRect(x * tileSize, y * tileSize, tileSize, tileSize, (cells[x][y].isBlack() ? blackColor : whiteColor));
        }
    }
}