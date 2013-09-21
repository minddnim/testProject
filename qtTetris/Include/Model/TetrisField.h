#ifndef TETRISFIELD_H
#define TETRISFIELD_H

#include <array>

class TetrisField
{
public:
    TetrisField();
    ~TetrisField();

private:
    static const int s_fldWidth = 10;
    static const int s_fldHeight = 20;
    array<array<int,s_fldWidth>, s_fldHeight> m_field;
};

#endif // TETRISFIELD_H
