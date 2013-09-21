#include "MyselfTetrimino.h"

void
MyselfTetrimino::RotToLeft()
{
    switch(m_rotAngle)
    {
    case ROT_0:     m_rotAngle = ROT_90;  break;
    case ROT_90:    m_rotAngle = ROT_180; break;
    case ROT_180:   m_rotAngle = ROT_270; break;
    case ROT_270:   m_rotAngle = ROT_0;   break;
    default: throw std::exception();
    }
    return;
}

void
MyselfTetrimino::RotToRight()
{
    switch(m_rotAngle)
    {
    case ROT_0:     m_rotAngle = ROT_270; break;
    case ROT_90:    m_rotAngle = ROT_0;   break;
    case ROT_180:   m_rotAngle = ROT_90;  break;
    case ROT_270:   m_rotAngle = ROT_180; break;
    default: throw std::exception();
    }
    return;
}

void
MyselfTetrimino::MoveDown()
{

}

void
MyselfTetrimino::MoveBottom()
{

}

Pos
MyselfTetrimino::GetNowPos() const
{
    return m_nowPos;
}

std::vector<Pos>
MyselfTetrimino::GetTetriminoPos() const
{
    auto blockPos = m_tet.GetTetriminoForm();
    for(auto p : blockPos) RotatePos(p);
    return blockPos;
}

void
MyselfTetrimino::RotatePos(Pos& pos)
{
    int px = pos.posX;
    int py = pos.posY;

    switch(m_rotAngle)
    {
    case ROT_0:
        pos.posX = px;
        pos.posY = py;
        break;
    case ROT_90:
        pos.posX = -py;
        pos.posY = px;
        break;
    case ROT_180:
        pos.posX = -px;
        pos.posY = -py;
        break;
    case ROT_270:
        pos.posX = py;
        pos.posY = -px;
        break;
    default:
        throw std::exception();
    }
}
