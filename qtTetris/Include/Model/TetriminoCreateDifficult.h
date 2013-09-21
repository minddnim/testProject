#ifndef TETRIMINOCREATEDIFFICULT_H
#define TETRIMINOCREATEDIFFICULT_H

#include <memory>

class Tetrimino;

class TetriminoCreateDifficult
{
public:
    TetriminoCreateDifficult();
    virtual ~TetriminoCreateDifficult();

    virtual std::shared_ptr<Tetrimino> CreateTetrimino();
};

#endif // TETRIMINOCREATEDIFFICULT_H
