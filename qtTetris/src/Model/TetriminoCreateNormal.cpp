#include "Tetrimino.h"
#include "Tetrimino_I.h"
#include "Tetrimino_J.h"
#include "Tetrimino_L.h"
#include "Tetrimino_O.h"
#include "Tetrimino_S.h"
#include "Tetrimino_T.h"
#include "Tetrimino_Z.h"
#include "TetriminoCreateNormal.h"
#include <random>
#include <memory>

std::shared_ptr<Tetrimino> TetriminoCreateNormal::CreateTetrimino()
{
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist(1,7);
    const Pos defaultPos = {0,0};
    switch(dist(rng))
    {
    case 1: return std::shared_ptr<Tetrimino>(new Tetrimino_I(defaultPos));
    case 2: return std::shared_ptr<Tetrimino>(new Tetrimino_J(defaultPos));
    case 3: return std::shared_ptr<Tetrimino>(new Tetrimino_L(defaultPos));
    case 4: return std::shared_ptr<Tetrimino>(new Tetrimino_O(defaultPos));
    case 5: return std::shared_ptr<Tetrimino>(new Tetrimino_S(defaultPos));
    case 6: return std::shared_ptr<Tetrimino>(new Tetrimino_T(defaultPos));
    case 7: return std::shared_ptr<Tetrimino>(new Tetrimino_Z(defaultPos));
    default: throw std::exception();
    }
    throw std::exception();
}
