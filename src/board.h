#ifndef BOARD_H
#define BOARD_H

#include "cell.h"

class Board {
private:
    Cell cells[8][8];
public:
    Cell& getCell(int x, int y);
};

#endif