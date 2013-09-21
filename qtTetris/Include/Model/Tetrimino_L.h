#ifndef TETRIMINO_L_H
#define TETRIMINO_L_H

#include "Tetrimino.h"

class Tetrimino_L : public Tetrimino
{
public:
    explicit Tetrimino_L(const Pos& pos)
        : Tetrimino(pos, 3, {{0,-20}, {0,0}, {20,0}, {40,0}})
    {}
    ~Tetrimino_L(){}
};

#endif // TETRIMINO_L_H
