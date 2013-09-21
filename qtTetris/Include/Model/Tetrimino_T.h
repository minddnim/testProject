#ifndef TETRIMINO_T_H
#define TETRIMINO_T_H

#include "Tetrimino.h"

class Tetrimino_T : public Tetrimino
{
public:
    Tetrimino_T()
        : Tetrimino(6, {{0,-1}, {-1,0}, {0,0}, {1,0}})
    {}
    ~Tetrimino_T(){}
};

#endif // TETRIMINO_T_H
