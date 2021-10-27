#ifndef BOARD_H
#define BOARD_H

#include "cell.h"

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

class Board {
private:
    Cell cells[BOARD_WIDTH][BOARD_HEIGHT];
public:
    Cell& getCell(int x, int y);
};

#endif