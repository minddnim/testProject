#ifndef TETRIMINO_Z_H
#define TETRIMINO_Z_H

#include "Tetrimino.h"

class Tetrimino_Z : public Tetrimino
{
public:
    Tetrimino_Z()
        : Tetrimino(7, {{1,-1}, {0,0}, {0,1}, {1,0}})
    {}
    ~Tetrimino_Z(){}
};

#endif // TETRIMINO_Z_H
