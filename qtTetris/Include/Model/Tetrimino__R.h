#ifndef TETRIMINO__R_H
#define TETRIMINO__R_H

#include "Tetrimino.h"

class Tetrimino__R : public Tetrimino
{
public:
    Tetrimino__R()
        : Tetrimino(7, {{-2,-2}, {-2,-1}, {-2,0}, {-2,1}, {-2,2}, {-1,-2}, {-1,0}, {0,-2}, {0,0}, {1,-1}, {1,1}, {2,2}})
    {}
    ~Tetrimino__R(){}
};

#endif // TETRIMINO__R_H
