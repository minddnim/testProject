#ifndef TETRIMINOCREATENORMAL_H
#define TETRIMINOCREATENORMAL_H

#include <memory>

class Tetrimino;

class TetriminoCreateNormal
{
public:
    TetriminoCreateNormal(){}
    virtual ~TetriminoCreateNormal(){}

    virtual std::shared_ptr<Tetrimino> CreateTetrimino();
};

#endif // TETRIMINOCREATENORMAL_H
