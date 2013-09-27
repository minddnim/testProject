#include "TetrisField.h"
#include <array>
//#include <vector>

TetrisField::TetrisField()
{
    for(int i = 0; i < s_fldHeight; ++i)
        _field.emplace_back();

    for(auto line : _field)
        line.fill(0);
}

void
TetrisField::AddBlock(const std::vector<Block>& blocks)
{
    for(auto block : blocks)
    {
        // ここの部分は処理が遅いので、後で修正する
        auto it = _field.begin();
        for(int py = 0; it != _field.end(); ++py, ++it)
            if(py == block.p.posY) (*it)[block.p.posX] = block.id;
    }
}

void
TetrisField::DeleteLine()
{
    _field.remove_if([](std::array<ColorID,s_fldWidth> line)
    {
        for(const auto x : line)
            if(x == 0) return false;
        return true;
    });
}

void
TetrisField::AddLine()
{
    int addLine = s_fldHeight - _field.size();
    for(int i=0; i < addLine; ++i)
    {
        _field.emplace_front();
    }
}

std::vector<Block>
TetrisField::GetTetrisField() const
{
    std::vector<Block> field;
    auto it = _field.begin();
    for(int py = 0; it != _field.end(); ++py, ++it)
    {
        for(int px = 0; px < (*it).size(); ++px)
        {
            if(0 != (*it)[px])
                field.emplace_back(Block({px, py}, (*it)[px], 1.0));
        }
    }
    return field;
}

bool
TetrisField::ExistBlock(const Pos& p) const
{
    return (0 != GetBlockColorID(p));
}

ColorID
TetrisField::GetBlockColorID(const Pos& p) const
{
    if(!IsPosInRange(p)) return -1;
    auto it = _field.begin();
    for(int py = 0; it != _field.end(); ++py, ++it)
        if(py == p.posY) return (*it)[p.posX];
    return -1;
}

bool
TetrisField::IsPosInRange(const Pos& p) const
{
    if(!((0 <= p.posX) && (p.posX < s_fldWidth))) return false;
    if(!((0 <= p.posY) && (p.posY < s_fldHeight))) return false;
    return true;
}
