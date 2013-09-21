#ifndef TETRIMINO_L_H
#define TETRIMINO_L_H

#include "Tetrimino.h"

class Tetrimino_L : public Tetrimino
{
public:
    Tetrimino_L()
        : Tetrimino(3, {{0,-1}, {0,0}, {1,0}, {2,0}})
    {}
    ~Tetrimino_L(){}
};

#endif // TETRIMINO_L_H
