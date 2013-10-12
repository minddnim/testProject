#include "Tetrimino.h"
#include "Tetrimino_I.h"
#include "Tetrimino_J.h"
#include "Tetrimino_L.h"
#include "Tetrimino_O.h"
#include "Tetrimino_S.h"
#include "Tetrimino_T.h"
#include "Tetrimino_Z.h"
#include "Tetrimino__A.h"
#include "Tetrimino__D.h"
#include "Tetrimino__E.h"
#include "Tetrimino__I.h"
#include "Tetrimino__M.h"
#include "Tetrimino__N.h"
#include "Tetrimino__R.h"
#include "Tetrimino__S.h"
#include "TetriminoCreateDifficult.h"

std::shared_ptr<Tetrimino> TetriminoCreateDifficult::CreateTetrimino()
{
    std::uniform_int_distribution<int> dist(1,8);
    switch(dist(_mt))
    {
    case 1: return std::shared_ptr<Tetrimino>(new Tetrimino_I);
    case 2: return std::shared_ptr<Tetrimino>(new Tetrimino_J);
    case 3: return std::shared_ptr<Tetrimino>(new Tetrimino_L);
    case 4: return std::shared_ptr<Tetrimino>(new Tetrimino_O);
    case 5: return std::shared_ptr<Tetrimino>(new Tetrimino_S);
    case 6: return std::shared_ptr<Tetrimino>(new Tetrimino_T);
    case 7: return std::shared_ptr<Tetrimino>(new Tetrimino_Z);
    default: break;
    }

    switch(dist(_mt))
    {
    case 1: return std::shared_ptr<Tetrimino>(new Tetrimino__A);
    case 2: return std::shared_ptr<Tetrimino>(new Tetrimino__D);
    case 3: return std::shared_ptr<Tetrimino>(new Tetrimino__E);
    case 4: return std::shared_ptr<Tetrimino>(new Tetrimino__I);
    case 5: return std::shared_ptr<Tetrimino>(new Tetrimino__M);
    case 6: return std::shared_ptr<Tetrimino>(new Tetrimino__N);
    case 7: return std::shared_ptr<Tetrimino>(new Tetrimino__R);
    case 8: return std::shared_ptr<Tetrimino>(new Tetrimino__S);
    default: throw std::exception();
    }
    throw std::exception();
}
