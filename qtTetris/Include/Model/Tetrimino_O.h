#ifndef TETRIMINO_O_H
#define TETRIMINO_O_H

#include "Tetrimino.h"

class Tetrimino_O : public Tetrimino
{
public:
    explicit Tetrimino_O(const Pos& pos)
        : Tetrimino(pos, 4, {{0,0}, {0,20}, {20,20}, {20,0}})
    {}
    ~Tetrimino_O(){};
};

#endif // TETRIMINO_O_H
