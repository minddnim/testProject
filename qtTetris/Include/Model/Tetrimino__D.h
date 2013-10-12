#ifndef TETRIMINO__D_H
#define TETRIMINO__D_H

#include "Tetrimino.h"

class Tetrimino__D : public Tetrimino
{
public:
    Tetrimino__D()
        : Tetrimino(2, {{-2,2}, {-2,1}, {-2,0}, {-2,-1}, {-2,-2}, {-1,2}, {-1,-2}, {0,2}, {0,-2}, {1,1}, {1,0}, {1,-1}})
    {}
    ~Tetrimino__D(){}
};

#endif // TETRIMINO__D_H
