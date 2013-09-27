#include "MyselfTetrimino.h"
#include "DataDefine.h"

const Pos MyselfTetrimino::s_startPos = {4,3};
const double MyselfTetrimino::s_alpha = 0.3;

void
MyselfTetrimino::RotToLeft()
{
    switch(_rotAngle)
    {
    case ROTATE_ANGLE::ROT_0:     _rotAngle = ROTATE_ANGLE::ROT_90;  break;
    case ROTATE_ANGLE::ROT_90:    _rotAngle = ROTATE_ANGLE::ROT_180; break;
    case ROTATE_ANGLE::ROT_180:   _rotAngle = ROTATE_ANGLE::ROT_270; break;
    case ROTATE_ANGLE::ROT_270:   _rotAngle = ROTATE_ANGLE::ROT_0;   break;
    default: throw std::exception();
    }
    return;
}

void
MyselfTetrimino::RotToRight()
{
    switch(_rotAngle)
    {
    case ROTATE_ANGLE::ROT_0:     _rotAngle = ROTATE_ANGLE::ROT_270; break;
    case ROTATE_ANGLE::ROT_90:    _rotAngle = ROTATE_ANGLE::ROT_0;   break;
    case ROTATE_ANGLE::ROT_180:   _rotAngle = ROTATE_ANGLE::ROT_90;  break;
    case ROTATE_ANGLE::ROT_270:   _rotAngle = ROTATE_ANGLE::ROT_180; break;
    default: throw std::exception();
    }
    return;
}

void
MyselfTetrimino::MoveRight()
{
    _nowPos.posX++;
}

void
MyselfTetrimino::MoveLeft()
{
    _nowPos.posX--;
}

void
MyselfTetrimino::MoveDown()
{
    _nowPos.posY++;
}

void MyselfTetrimino::ResetPosition()
{
    _nowPos = s_startPos;
}

void
MyselfTetrimino::SetGhostPos(const Pos& p)
{
    _ghostPos = p;
}

void
MyselfTetrimino::SetNowPos(const Pos& p)
{
    _nowPos = p;
}

Pos
MyselfTetrimino::GetNowPos() const
{
    return _nowPos;
}

std::vector<Block>
MyselfTetrimino::GetTetriminoPos() const
{
    if(!_tet) throw std::exception();

    auto blockPos = _tet->GetTetriminoForm();
    const auto clrId = _tet->GetBlockColorID();
    std::vector<Block> ps;
    for(auto p : blockPos)
    {
        const Pos rotPos = RotatePos(p);
        const int px = rotPos.posX + _nowPos.posX;
        const int py = rotPos.posY + _nowPos.posY;
        ps.emplace_back(Block({px, py}, clrId));
    }
    return ps;
}

std::vector<Block>
MyselfTetrimino::GetTetriminoGhostPos() const
{
    if(!_tet) throw std::exception();

    auto blockPos = _tet->GetTetriminoForm();
    const auto clrId = _tet->GetBlockColorID();
    std::vector<Block> ps;
    for(auto p : blockPos)
    {
        const Pos rotPos = RotatePos(p);
        const int px = rotPos.posX + _ghostPos.posX;
        const int py = rotPos.posY + _ghostPos.posY;
        ps.emplace_back(Block({px, py}, clrId, s_alpha));
    }
    return ps;
}

Pos
MyselfTetrimino::RotatePos(const Pos& p) const
{
    int px = p.posX;
    int py = p.posY;
    Pos rotPos = {0, 0};

    switch(_rotAngle)
    {
    case ROTATE_ANGLE::ROT_0:
        rotPos.posX = px;
        rotPos.posY = py;
        break;
    case ROTATE_ANGLE::ROT_90:
        rotPos.posX = -py;
        rotPos.posY = px;
        break;
    case ROTATE_ANGLE::ROT_180:
        rotPos.posX = -px;
        rotPos.posY = -py;
        break;
    case ROTATE_ANGLE::ROT_270:
        rotPos.posX = py;
        rotPos.posY = -px;
        break;
    default:
        throw std::exception();
    }
    return rotPos;
}

void
MyselfTetrimino::SetTetrimino(std::shared_ptr<Tetrimino> tet)
{
    if(!tet) return;
    _tet = tet;
}
