#include "TetrisField.h"
#include <array>
//#include <vector>

TetrisField::TetrisField()
{
    for(int i = 0; i < s_fldHeight; ++i)
        m_field.emplace_back();

    for(auto line : m_field)
        line.fill(0);

//    // テスト表示用データ
//    auto it = m_field.begin(); ++it;++it;++it;++it;
//    for(; it != m_field.end(); ++it)
//        (*it)[2] = 1;
}

void
TetrisField::AddBlock(const std::vector<Block>& blocks)
{
    for(auto block : blocks)
    {
        // ここの部分は処理が遅いので、後で修正する
        auto it = m_field.begin();
        for(int py = 0; it != m_field.end(); ++py, ++it)
            if(py == block.p.posY) (*it)[block.p.posX] = block.id;
    }
}

void
TetrisField::DeleteLine()
{
    m_field.remove_if([](std::array<ColorID,s_fldWidth> line)
    {
        for(const auto x : line)
            if(x == 0) return false;
        return true;
    });
}

void
TetrisField::AddLine()
{
    int addLine = s_fldHeight - m_field.size();
    for(int i=0; i < addLine; ++i)
    {
        m_field.emplace_front();
    }
}

std::vector<Block>
TetrisField::GetTetrisField() const
{
    std::vector<Block> field;
    auto it = m_field.begin();
    for(int py = 0; it != m_field.end(); ++py, ++it)
    {
        for(int px = 0; px < (*it).size(); ++px)
        {
            if(0 != (*it)[px])
                field.emplace_back(Block({px, py}, (*it)[px]));
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
    auto it = m_field.begin();
    for(int py = 0; it != m_field.end(); ++py, ++it)
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
