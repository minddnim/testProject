#include "GameManeger.h"
#include "TetriminoCreateNormal.h"

std::vector<Block>
GameManeger::GetField() const
{
    return m_field.GetTetrisField();
}

std::vector<Block>
GameManeger::GetCtrlBlock() const
{
    return m_myBlock.GetTetriminoPos();
}

double
GameManeger::GetDetailPos() const
{
    return static_cast<double>(m_freeFallCnt)/s_intvalTime;
}

void
GameManeger::GameStart()
{
    TetriminoCreateNormal factory;
    m_myBlock.SetTetrimino(factory.CreateTetrimino());
}

void
GameManeger::update()
{
    m_freeFallCnt++;
    if(m_freeFallCnt >= s_intvalTime)
    {
        m_freeFallCnt = 0;
        FreeFall();
    }
}

void
GameManeger::TryRotateRight()
{
    m_myBlock.RotToRight();
}

void
GameManeger::TryRotateLeft()
{
    m_myBlock.RotToLeft();
}

void
GameManeger::TryMoveRight()
{
    m_myBlock.MoveRight();
}

void
GameManeger::TryMoveLeft()
{
    m_myBlock.MoveLeft();
}

void
GameManeger::TryMoveDown()
{
    m_myBlock.MoveDown();
}

void
GameManeger::TryMoveButtom()
{
    m_myBlock.MoveBottom();
}

void
GameManeger::FreeFall()
{
    m_myBlock.MoveDown();
}
