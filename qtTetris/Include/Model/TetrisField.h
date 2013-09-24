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
    std::list< std::array<ColorID,s_fldWidth> > m_field;

private:
    void AddBlock(const Pos& basePos, const Tetrimino& tet);
    void DeleteLine();

public:
    std::vector<Block> GetTetrisField() const;
};

#endif // TETRISFIELD_H
