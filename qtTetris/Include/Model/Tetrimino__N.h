#ifndef TETRIMINO__N_H
#define TETRIMINO__N_H

#include "Tetrimino.h"

class Tetrimino__N : public Tetrimino
{
public:
    Tetrimino__N()
        : Tetrimino(6, {{2,2}, {2,1}, {2,0}, {2,-1}, {2,-2}, {1,1}, {0,0}, {-1,-1}, {-2,2}, {-2,1}, {-2,0}, {-2,-1}, {-2,-2}})
    {}
    ~Tetrimino__N(){}
};

#endif // TETRIMINO__N_H
