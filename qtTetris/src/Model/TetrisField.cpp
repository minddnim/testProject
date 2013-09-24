#include "TetrisField.h"
#include <array>
//#include <vector>

TetrisField::TetrisField()
{
    for(int i = 0; i < s_fldHeight; ++i)
        m_field.emplace_back();

    for(auto line : m_field)
        line.fill(0);

    // テスト表示用データ
    auto it = m_field.begin(); ++it;++it;++it;
    for(; it != m_field.end(); ++it)
        (*it)[2] = 1;
}

void
TetrisField::AddBlock(const Pos &basePos, const Tetrimino &tet)
{
    auto blocks = tet.GetTetriminoForm();
    const auto clrId = tet.GetBlockColorID();

    for(auto block : blocks)
    {
        const int px = block.posX + basePos.posX;
        const int py = block.posY + basePos.posY;

        // ここの部分は処理が遅いので、後で修正する
        auto it = m_field.begin();
        for(int i = 0; it != m_field.end(); ++i, ++it)
            if(i == px) (*it)[py] = clrId;
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
