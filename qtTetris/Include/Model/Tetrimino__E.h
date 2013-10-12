#ifndef TETRIMINO__E_H
#define TETRIMINO__E_H

#include "Tetrimino.h"

class Tetrimino__E : public Tetrimino
{
public:
    Tetrimino__E()
        : Tetrimino(3, {{-2,2}, {-2,1}, {-2,0}, {-2,-1}, {-2,-2}, {-1,2}, {-1,0}, {-1,-2}, {0,2}, {0,0}, {0,-2}, {1,2}, {1,-2}, {2,2}, {2,-2}})
    {}
    ~Tetrimino__E(){}
};

#endif // TETRIMINO__E_H
