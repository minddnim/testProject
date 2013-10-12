#ifndef TETRIMINO__I_H
#define TETRIMINO__I_H

#include "Tetrimino.h"

class Tetrimino__I : public Tetrimino
{
public:
    Tetrimino__I()
        : Tetrimino(4, {{0,2}, {0,1}, {0,0}, {0,-1}, {0,-2}})
    {}
    ~Tetrimino__I(){}
};

#endif // TETRIMINO__I_H
