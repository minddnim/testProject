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

std::vector<Block>
GameManeger::GetNextBlock() const
{
    return _myBlock.GetNextTetriminoPos();
}

std::vector<Block>
GameManeger::GetCtrlGhostBlock() const
{
    return _myBlock.GetTetriminoGhostPos();
}

double
GameManeger::GetDetailPos() const
{
    return static_cast<double>(_freeFallCnt)/s_intvalTime;
}

int
GameManeger::GetDeleteLineCnt() const
{
    return _deleteLineCnt;
}

int
GameManeger::GetLevel() const
{
    return static_cast<int>(_deleteLineCnt/s_levelUpVal) + 1;
}

void
GameManeger::GameStart()
{
    Initialize();
}

bool
GameManeger::IsGameOver()
{
    return _field.IsFieldHeightOver();
}

void
GameManeger::Initialize()
{
    _field.ClearField();
    _myBlock.ResetPosition();
    _myBlock.SetNextTetrimino(_tetriminoFactory->CreateTetrimino());
    _myBlock.SetTetrimino();
    _myBlock.SetNextTetrimino(_tetriminoFactory->CreateTetrimino());
    _freeFallCnt = -s_intvalTime;
    _deleteLineCnt = 0;
}

bool
GameManeger::Update()
{
    const bool isGameOver = _field.IsFieldHeightOver();
    if(!isGameOver)
    {
        _freeFallCnt += GetLevel();
        if(_freeFallCnt >= 0)
        {
            _freeFallCnt = -s_intvalTime;
            FreeFall();
        }
        return true;
    }
    return false;
}

void
GameManeger::UpdateGhostPos()
{
    auto nowPos = _myBlock.GetNowPos();
    while(CanMoveTetrimino({0,1}))
    {
        _myBlock.MoveDown();
    }
    auto bottomPos = _myBlock.GetNowPos();
    _myBlock.SetGhostPos(bottomPos);
    _myBlock.SetNowPos(nowPos);
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

void GameManeger::SetDifficultMode()
{
    if(_tetriminoFactory) delete _tetriminoFactory;
    _tetriminoFactory = new TetriminoCreateDifficult();
}

void GameManeger::SetNormalMode()
{
    if(_tetriminoFactory) delete _tetriminoFactory;
    _tetriminoFactory = new TetriminoCreateNormal();
}

void
GameManeger::DecisionMyTetrimino()
{
    _field.AddBlock(_myBlock.GetTetriminoPos());
    _deleteLineCnt += _field.DeleteLine();
    _field.AddLine();
    _myBlock.ResetPosition();
    _myBlock.SetTetrimino();
    _myBlock.SetNextTetrimino(_tetriminoFactory->CreateTetrimino());
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
