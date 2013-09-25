#include "MyselfTetrimino.h"
#include "DataDefine.h"

const Pos MyselfTetrimino::s_startPos = {4,3};

void
MyselfTetrimino::RotToLeft()
{
    switch(m_rotAngle)
    {
    case ROTATE_ANGLE::ROT_0:     m_rotAngle = ROTATE_ANGLE::ROT_90;  break;
    case ROTATE_ANGLE::ROT_90:    m_rotAngle = ROTATE_ANGLE::ROT_180; break;
    case ROTATE_ANGLE::ROT_180:   m_rotAngle = ROTATE_ANGLE::ROT_270; break;
    case ROTATE_ANGLE::ROT_270:   m_rotAngle = ROTATE_ANGLE::ROT_0;   break;
    default: throw std::exception();
    }
    return;
}

void
MyselfTetrimino::RotToRight()
{
    switch(m_rotAngle)
    {
    case ROTATE_ANGLE::ROT_0:     m_rotAngle = ROTATE_ANGLE::ROT_270; break;
    case ROTATE_ANGLE::ROT_90:    m_rotAngle = ROTATE_ANGLE::ROT_0;   break;
    case ROTATE_ANGLE::ROT_180:   m_rotAngle = ROTATE_ANGLE::ROT_90;  break;
    case ROTATE_ANGLE::ROT_270:   m_rotAngle = ROTATE_ANGLE::ROT_180; break;
    default: throw std::exception();
    }
    return;
}

void
MyselfTetrimino::MoveRight()
{
    m_nowPos.posX++;
}

void
MyselfTetrimino::MoveLeft()
{
    m_nowPos.posX--;
}

void
MyselfTetrimino::MoveDown()
{
    m_nowPos.posY++;
}

void
MyselfTetrimino::MoveBottom()
{
}

void MyselfTetrimino::ResetPosition()
{
    m_nowPos = s_startPos;
}

Pos
MyselfTetrimino::GetNowPos() const
{
    return m_nowPos;
}

std::vector<Block>
MyselfTetrimino::GetTetriminoPos() const
{
    if(!m_tet) throw std::exception();

    auto blockPos = m_tet->GetTetriminoForm();
    const auto clrId = m_tet->GetBlockColorID();
    std::vector<Block> ps;
    for(auto p : blockPos)
    {
        const Pos rotPos = RotatePos(p);
        const int px = rotPos.posX + m_nowPos.posX;
        const int py = rotPos.posY + m_nowPos.posY;
        ps.emplace_back(Block({px, py}, clrId));
    }
    return ps;
}

Pos
MyselfTetrimino::RotatePos(const Pos& p) const
{
    int px = p.posX;
    int py = p.posY;
    Pos rotPos = {0, 0};

    switch(m_rotAngle)
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
    m_tet = tet;
}
