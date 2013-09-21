#ifndef TETRIMINO_I_H
#define TETRIMINO_I_H

#include "Tetrimino.h"

class Tetrimino_I : public Tetrimino
{
public:
    Tetrimino_I()
        : Tetrimino(1, {{-1,0}, {0,0}, {1,0}, {2,0}})
    {}
    ~Tetrimino_I(){}
};

#endif // TETRIMINO_I_H
