#ifndef TETRIMINO_J_H
#define TETRIMINO_J_H

#include "Tetrimino.h"

class Tetrimino_J : public Tetrimino
{
public:
    explicit Tetrimino_J(const Pos& pos)
        : Tetrimino(pos, 2, {{0,-20}, {0,0}, {-20,0}, {-40,0}})
    {}
    ~Tetrimino_J(){};
};

#endif // TETRIMINO_J_H
