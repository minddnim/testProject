#ifndef TETRIMINO_T_H
#define TETRIMINO_T_H

#include "Tetrimino.h"

class Tetrimino_T : public Tetrimino
{
public:
    explicit Tetrimino_T(const Pos& pos)
        : Tetrimino(pos, 6, {{0,-20}, {-20,0}, {0,0}, {20,0}})
    {}
    ~Tetrimino_T(){}
};

#endif // TETRIMINO_T_H
