#include "Tetrimino.h"
#include "Tetrimino_I.h"
#include "TetriminoCreateDifficult.h"

std::shared_ptr<Tetrimino> TetriminoCreateDifficult::CreateTetrimino()
{
    return std::shared_ptr<Tetrimino>(new Tetrimino_I);
}
