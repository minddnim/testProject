#include "GameManeger.h"

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
    m_myBlock.SetTetrimino(m_tetriminoFactory.CreateTetrimino());
}

void
GameManeger::update()
{
    m_freeFallCnt++;
    if(m_freeFallCnt >= 0)
    {
        m_freeFallCnt = -s_intvalTime;
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
    if(CanMoveTetrimino({1,0}))
        m_myBlock.MoveRight();
}

void
GameManeger::TryMoveLeft()
{
    if(CanMoveTetrimino({-1,0}))
        m_myBlock.MoveLeft();
}

void
GameManeger::TryMoveDown()
{
    if(CanMoveTetrimino({0,1}))
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
    if(CanMoveTetrimino({0,1}))
    {
        m_myBlock.MoveDown();
    }
    else
    {
        DecisionMyTetrimino();
        m_field.DeleteLine();
        m_field.AddLine();
        m_myBlock.ResetPosition();
        m_myBlock.SetTetrimino(m_tetriminoFactory.CreateTetrimino());
    }
}

void
GameManeger::DecisionMyTetrimino()
{
    m_field.AddBlock(m_myBlock.GetTetriminoPos());
}

bool
GameManeger::CanMoveTetrimino(const Pos& movePos) const
{
    const std::vector<Block> blocks = m_myBlock.GetTetriminoPos();
    for(const auto block : blocks)
    {
        int px = block.p.posX + movePos.posX;
        int py = block.p.posY + movePos.posY;
        if(m_field.ExistBlock({px, py})) return false;
    }
    return true;
}
