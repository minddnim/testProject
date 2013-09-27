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
        : _nowPos(s_startPos)
        , _rotAngle(ROTATE_ANGLE::ROT_0)
        , _tet(nullptr)
    {}

    ~MyselfTetrimino(){}

private:
    Pos _nowPos;
    ROTATE_ANGLE _rotAngle;
    std::shared_ptr<Tetrimino> _tet;
    static const Pos s_startPos;

public:
    void RotToLeft();
    void RotToRight();
    void MoveRight();
    void MoveLeft();
    void MoveDown();
    void ResetPosition();

    Pos GetNowPos() const;
    std::vector<Block> GetTetriminoPos() const;
    void SetTetrimino(std::shared_ptr<Tetrimino> tet);

private:
    Pos RotatePos(const Pos& p) const;
};

#endif // MYSELFTETRIMINO_H
