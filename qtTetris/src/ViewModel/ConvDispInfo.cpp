#include "ConvDispInfo.h"
#include "GameManeger.h"

ConvDispInfo::ConvDispInfo()
{
    // 両側の壁の定義
    for(int py = 0; py < s_fldH; ++py)
    {
        _blockWall.emplace_back(Block({-1, py}, s_blockColorID));
        _blockWall.emplace_back(Block({s_fldW, py}, s_blockColorID));
    }

    // 底の壁の定義
    for(int px = -1; px < s_fldW+1; ++px)
    {
        _blockWall.emplace_back(Block({px, s_fldH}, s_blockColorID));
    }
}

std::vector<Block>
ConvDispInfo::GetWallData() const
{
    return _blockWall;
}

std::vector<Block>
ConvDispInfo::GetFieldData() const
{
    return GameManeger::GetInstance()->GetField();
}

std::vector<Block>
ConvDispInfo::GetCtrlBlockData() const
{
    return GameManeger::GetInstance()->GetCtrlBlock();
}

std::vector<Block>
ConvDispInfo::GetCtrlGhostBlockData() const
{
    GameManeger::GetInstance()->UpdateGhostPos();
    return GameManeger::GetInstance()->GetCtrlGhostBlock();
}

double
ConvDispInfo::GetDetailPos() const
{
    return GameManeger::GetInstance()->GetDetailPos();
}

int ConvDispInfo::GetDeleteLineCnt() const
{
    return GameManeger::GetInstance()->GetDeleteLineCnt();
}

