#ifndef TETRIMINO__M_H
#define TETRIMINO__M_H

#include "Tetrimino.h"

class Tetrimino__M : public Tetrimino
{
public:
    Tetrimino__M()
        : Tetrimino(5, {{2,-2}, {2,-1}, {2,0}, {2,1}, {2,2}, {1,-1}, {0,0}, {-1,-1}, {-2,-2}, {-2,-1}, {-2,0}, {-2,1}, {-2,2}})
    {}
    ~Tetrimino__M(){}
};

#endif // TETRIMINO__M_H
