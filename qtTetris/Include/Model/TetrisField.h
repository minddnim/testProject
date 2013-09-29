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
    static const int s_fldHeightMargin = 4;
    static const int s_fldWidth = 10;
    static const int s_fldHeight = 20 + s_fldHeightMargin;
    std::list<std::array<ColorID,s_fldWidth>> _field;

private:
    bool IsPosInRange(const Pos& p) const;

public:
    void AddBlock(const std::vector<Block> &blocks);
    int DeleteLine();
    void AddLine();
    void ClearField();

    std::vector<Block> GetTetrisField() const;
    bool ExistBlock(const Pos& p) const;
    ColorID GetBlockColorID(const Pos& p) const;
    bool IsFieldHeightOver() const;
};

#endif // TETRISFIELD_H
