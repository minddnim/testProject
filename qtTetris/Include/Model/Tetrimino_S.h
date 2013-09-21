#ifndef TETRIMINO_S_H
#define TETRIMINO_S_H

#include "Tetrimino.h"

class Tetrimino_S : public Tetrimino
{
public:
    explicit Tetrimino_S(const Pos& pos)
        : Tetrimino(pos, 5, {{-20,0}, {0,0}, {0,-20}, {20,-20}})
    {}
    ~Tetrimino_S(){};
};

#endif // TETRIMINO_S_H
