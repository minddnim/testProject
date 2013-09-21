#ifndef TETRIMINO_O_H
#define TETRIMINO_O_H

#include "Tetrimino.h"

class Tetrimino_O : public Tetrimino
{
public:
    Tetrimino_O()
        : Tetrimino(4, {{0,0}, {0,1}, {1,1}, {1,0}})
    {}
    ~Tetrimino_O(){}
};

#endif // TETRIMINO_O_H
