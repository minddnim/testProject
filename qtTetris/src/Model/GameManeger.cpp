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
GameManeger::FreeFall()
{
    m_myBlock.MoveDown();
}
