#ifndef MYSELFTETRIMINO_H
#define MYSELFTETRIMINO_H

#include "Tetrimino.h"
#include "DataDefine.h"
#include <vector>
#include <memory>

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
    MyselfTetrimino()
        : m_nowPos(s_startPos)
        , m_rotAngle(ROTATE_ANGLE::ROT_0)
        , m_tet(nullptr)
    {}

    ~MyselfTetrimino(){}

private:
    Pos m_nowPos;
    ROTATE_ANGLE m_rotAngle;
    std::shared_ptr<Tetrimino> m_tet;
    static const Pos s_startPos;

public:
    void RotToLeft();
    void RotToRight();
    void MoveRight();
    void MoveLeft();
    void MoveDown();
    void MoveBottom();
    void ResetPosition();

    Pos GetNowPos() const;
    std::vector<Block> GetTetriminoPos() const;
    void SetTetrimino(std::shared_ptr<Tetrimino> tet);

private:
    Pos RotatePos(const Pos& p) const;
};

#endif // MYSELFTETRIMINO_H
