#ifndef TETRIMINO_J_H
#define TETRIMINO_J_H

#include "Tetrimino.h"

class Tetrimino_J : public Tetrimino
{
public:
    Tetrimino_J()
        : Tetrimino(2, {{0,-1}, {0,0}, {-1,0}, {-2,0}})
    {}
    ~Tetrimino_J(){}
};

#endif // TETRIMINO_J_H
