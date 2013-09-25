#ifndef TETRIMINOCREATENORMAL_H
#define TETRIMINOCREATENORMAL_H

#include <memory>
#include <random>

class Tetrimino;

class TetriminoCreateNormal
{
public:
    TetriminoCreateNormal()
//        : m_rng(std::random_device()())
        : m_randDevice()
        , m_mt(m_randDevice())
    {}
    virtual ~TetriminoCreateNormal(){}

    virtual std::shared_ptr<Tetrimino> CreateTetrimino();
    std::random_device m_randDevice;
    std::mt19937 m_mt;
};

#endif // TETRIMINOCREATENORMAL_H
