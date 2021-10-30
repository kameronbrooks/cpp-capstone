#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include "globals.h"


class Renderer;

class Board {
private:
    Cell cells[BOARD_WIDTH][BOARD_HEIGHT];
public:
    Board();
    Cell* getCell(int x, int y);
    void draw(Renderer* renderer);



};

#endif