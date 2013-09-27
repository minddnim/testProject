#include "GameManeger.h"

std::vector<Block>
GameManeger::GetField() const
{
    return _field.GetTetrisField();
}

std::vector<Block>
GameManeger::GetCtrlBlock() const
{
    return _myBlock.GetTetriminoPos();
}

double
GameManeger::GetDetailPos() const
{
    return static_cast<double>(_freeFallCnt)/s_intvalTime;
}

void
GameManeger::GameStart()
{
    _myBlock.SetTetrimino(_tetriminoFactory.CreateTetrimino());
}

void
GameManeger::update()
{
    _freeFallCnt++;
    if(_freeFallCnt >= 0)
    {
        _freeFallCnt = -s_intvalTime;
        FreeFall();
    }
}

void
GameManeger::TryRotateRight()
{
    _myBlock.RotToRight();
    if(!CanMoveTetrimino({0,0}))
        _myBlock.RotToLeft();
}

void
GameManeger::TryRotateLeft()
{
    _myBlock.RotToLeft();
    if(!CanMoveTetrimino({0,0}))
        _myBlock.RotToRight();
}

void
GameManeger::TryMoveRight()
{
    if(CanMoveTetrimino({1,0}))
        _myBlock.MoveRight();
}

void
GameManeger::TryMoveLeft()
{
    if(CanMoveTetrimino({-1,0}))
        _myBlock.MoveLeft();
}

void
GameManeger::TryMoveDown()
{
    if(CanMoveTetrimino({0,1}))
    {
        _myBlock.MoveDown();
    }
    else
    {
        DecisionMyTetrimino();
    }
}

void
GameManeger::TryMoveButtom()
{
    while(CanMoveTetrimino({0,1}))
    {
        _myBlock.MoveDown();
    }
    DecisionMyTetrimino();
}

void
GameManeger::FreeFall()
{
    if(CanMoveTetrimino({0,1}))
    {
        _myBlock.MoveDown();
    }
    else
    {
        DecisionMyTetrimino();
    }
}

void
GameManeger::DecisionMyTetrimino()
{
    _field.AddBlock(_myBlock.GetTetriminoPos());
    _field.DeleteLine();
    _field.AddLine();
    _myBlock.ResetPosition();
    _myBlock.SetTetrimino(_tetriminoFactory.CreateTetrimino());
    _freeFallCnt = -s_intvalTime;
}

bool
GameManeger::CanMoveTetrimino(const Pos& movePos) const
{
    const std::vector<Block> blocks = _myBlock.GetTetriminoPos();
    for(const auto block : blocks)
    {
        int px = block.p.posX + movePos.posX;
        int py = block.p.posY + movePos.posY;
        if(_field.ExistBlock({px, py})) return false;
    }
    return true;
}
