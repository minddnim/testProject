#ifndef MYSELFTETRIMINO_H
#define MYSELFTETRIMINO_H

#include "Tetrimino.h"
#include "DataDefine.h"
#include <vector>


class MyselfTetrimino
{
private:
    enum class ROTATE_ANGLE
    {
        ROT_0,
        ROT_90,
        ROT_180,
        ROT_270
    };

public:
    explicit MyselfTetrimino(Tetrimino& tet)
        : m_nowPos({0,0})
        , m_rotAngle(ROTATE_ANGLE::ROT_0)
        , m_tet(tet)
    {}

    ~MyselfTetrimino(){}

private:
    Pos m_nowPos;
    ROTATE_ANGLE m_rotAngle;
    Tetrimino& m_tet;

public:
    void RotToLeft();
    void RotToRight();
    void MoveDown();
    void MoveBottom();

    Pos GetNowPos() const;
    std::vector<Pos> GetTetriminoPos();

private:
    void RotatePos(Pos& pos);
};

#endif // MYSELFTETRIMINO_H
