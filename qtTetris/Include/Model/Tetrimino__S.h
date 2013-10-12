#ifndef TETRIMINO__S_H
#define TETRIMINO__S_H

#include "Tetrimino.h"

class Tetrimino__S : public Tetrimino
{
public:
    Tetrimino__S()
        : Tetrimino(8, {{2,2}, {2,1}, {2,0}, {2,-2}, {1,2}, {1,0}, {1,-2}, {0,2}, {0,0}, {0,-2}, {-1,2}, {-1,0}, {-1,-2}, {-2,2}, {-2,0}, {-2,-1}, {-2,-2}})
    {}
    ~Tetrimino__S(){}
};

#endif // TETRIMINO__S_H
