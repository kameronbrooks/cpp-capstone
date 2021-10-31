#ifndef RELATION_MATRIX_H
#define RELATION_MATRIX_H
#include <memory>
#include <vector>
#include <unordered_map>
#include "piece.h"
#include "cell.h"
#include "board.h"


template<class T>
class RelationMatrix {
public:
    
    class CellNode {
    public:
        void clear() {
            _items.clear();
        }
        void add(T* t) {
            _items.push_back(t);
        }
        bool contains(T* t) {
            for(auto item: _items) {
                if(item == t)
                    return true;
            }
            return false;
        }
    private:
        std::vector<T*> _items;
    };
private:
    RelationMatrix <T>::CellNode _matrix[BOARD_WIDTH][BOARD_HEIGHT];

public:

    void clear() {
        for(int y = 0; y < BOARD_HEIGHT; ++y) {
            for(int x = 0; x < BOARD_WIDTH; ++x) {
                _matrix[x][y].clear();
            }
        }
    }
    
    void add(T* item, int x, int y) {
        _matrix[x][y].add(item);
    }

    bool contains(T* item, int x, int y) {
        return _matrix[x][y].contains(item);
    }

};

#endif