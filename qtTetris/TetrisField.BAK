#ifndef TETRISFIELD_H
#define TETRISFIELD_H

#include "DataDefine.h"
#include "Tetrimino.h"
#include <list>
#include <array>

class TetrisField
{
public:
    TetrisField();
    ~TetrisField(){}

private:
    static const int s_fldWidth = 10;
    static const int s_fldHeight = 20+4;
    std::list<std::array<ColorID,s_fldWidth>> m_field;

private:
    bool IsPosInRange(const Pos& p) const;

public:
    void AddBlock(const std::vector<Block> &blocks);
    void DeleteLine();
    void AddLine();

    std::vector<Block> GetTetrisField() const;
    bool ExistBlock(const Pos& p) const;
    ColorID GetBlockColorID(const Pos& p) const;
};

#endif // TETRISFIELD_H
