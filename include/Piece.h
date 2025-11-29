#ifndef PIECE_H
#define PIECE_H

#include "core_class.h"
#include <vector>

enum class PieceType { I, O, T, L, J, S, Z };

class Piece {
public:
    Piece(PieceType type = PieceType::I, unsigned int pivotRow = 0, unsigned int pivotCol = 0);

    PieceType type() const { return _type; }
    unsigned int pivot_row() const { return _blocks[_pivot_idx].row(); }
    unsigned int pivot_col() const { return _blocks[_pivot_idx].column(); }

    std::vector<Block> getBlocks() const { return _blocks; }
    unsigned int size() const { return static_cast<unsigned int>(_blocks.size()); }

    void move(Move m);
    void rotateDirect();   
    void rotateIndirect();
    void setPivotPosition(unsigned int row, unsigned int col);

private:
    PieceType _type;
    std::vector<Block> _blocks;   
    unsigned int _pivot_idx;     

    void initializeBlocks(unsigned int pivotRow, unsigned int pivotCol);
};
#endif 