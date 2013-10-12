#ifndef TETRIMINOCREATEDIFFICULT_H
#define TETRIMINOCREATEDIFFICULT_H

#include <memory>
#include <random>
#include <time.h>
#include <TetriminoFactory.h>

class Tetrimino;

class TetriminoCreateDifficult : public TetriminoFactory
{
public:
    TetriminoCreateDifficult()
        : _mt(time(nullptr))
    {}

    virtual ~TetriminoCreateDifficult(){}

    virtual std::shared_ptr<Tetrimino> CreateTetrimino();
    std::mt19937 _mt;
};

#endif // TETRIMINOCREATEDIFFICULT_H
