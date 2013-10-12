#ifndef TETRIMINOFACTORY_H
#define TETRIMINOFACTORY_H

#include <memory>

class Tetrimino;

class TetriminoFactory
{
public:
    TetriminoFactory(){}
    virtual ~TetriminoFactory(){}

    virtual std::shared_ptr<Tetrimino> CreateTetrimino() = 0;
};

#endif // TETRIMINOFACTORY_H
