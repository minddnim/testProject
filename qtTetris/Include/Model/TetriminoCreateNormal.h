#ifndef TETRIMINOCREATENORMAL_H
#define TETRIMINOCREATENORMAL_H

#include <memory>
#include <random>
#include <time.h>

class Tetrimino;

class TetriminoCreateNormal
{
public:
    TetriminoCreateNormal()
//        : _rng(std::rando_device()())
        : _randDevice()
        , _mt(time(nullptr))
    {}
    virtual ~TetriminoCreateNormal(){}

    virtual std::shared_ptr<Tetrimino> CreateTetrimino();
    std::random_device _randDevice;
    std::mt19937 _mt;
};

#endif // TETRIMINOCREATENORMAL_H
