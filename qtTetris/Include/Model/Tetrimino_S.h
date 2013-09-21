#ifndef TETRIMINO_S_H
#define TETRIMINO_S_H

#include "Tetrimino.h"

class Tetrimino_S : public Tetrimino
{
public:
    Tetrimino_S()
        : Tetrimino(5, {{-1,0}, {0,0}, {0,-1}, {1,-1}})
    {}
    ~Tetrimino_S(){}
};

#endif // TETRIMINO_S_H
