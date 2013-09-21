#ifndef TETRIMINO_I_H
#define TETRIMINO_I_H

#include "Tetrimino.h"

class Tetrimino_I : public Tetrimino
{
public:
    explicit Tetrimino_I(const Pos& pos)
        : Tetrimino(pos, 1, {{-20,0}, {0,0}, {20,0}, {40,0}})
    {}
    ~Tetrimino_I(){}
};

#endif // TETRIMINO_I_H
