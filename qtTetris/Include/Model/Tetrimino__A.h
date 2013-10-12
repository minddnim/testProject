#ifndef TETRIMINO__A_H
#define TETRIMINO__A_H

#include "Tetrimino.h"

class Tetrimino__A : public Tetrimino
{
public:
    Tetrimino__A()
        : Tetrimino(1, {{2,0}, {2,1}, {2,2}, {1,-1}, {1,0}, {0,-2}, {0,0}, {-1,-1}, {-1,0}, {-2,0}, {-2,1}, {-2,2}})
    {}
    ~Tetrimino__A(){}
};

#endif // TETRIMINO__A_H
