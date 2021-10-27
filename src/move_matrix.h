#ifndef MOVE_MATRIX_H
#define MOVE_MATRIX_H
#include <memory>
#include <vector>
#include <unordered_map>
#include "piece.h"
#include "cell.h"
#include "board.h"

class MoveMatrix {
public:
    class CellNode {
    public:

    private:
        Cell* _cell;
        std::vector<Piece*> _pieces;
    };

    void clear();
    void add(Piece* piece, int x, int y);

private:
    CellNode matrix[BOARD_WIDTH][BOARD_HEIGHT];
    std::unordered_map<Piece*, std::vector<CellNode*>> _cellNodeLookup;
};

#endif