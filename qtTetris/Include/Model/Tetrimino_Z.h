#ifndef TETRIMINO_Z_H
#define TETRIMINO_Z_H

#include "Tetrimino.h"

class Tetrimino_Z : public Tetrimino
{
public:
    explicit Tetrimino_Z(const Pos& pos)
        : Tetrimino(pos, 7, {{20,-20}, {0,0}, {0,20}, {20,0}})
    {}
    ~Tetrimino_Z(){}
};

#endif // TETRIMINO_Z_H
