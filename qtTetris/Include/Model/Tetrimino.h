#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <vector>
#include "DataDefine.h"

class Tetrimino
{
public:
    Tetrimino(const Pos& pos, ColorID cid, const std::vector<Pos>& form)
            : m_BasePos(pos)
            , m_ColorID(cid)
            , m_Form(form)
    {}

    virtual ~Tetrimino(){};

    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void MoveBottom();

protected:
    Pos m_BasePos;
    const ColorID m_ColorID;
    std::vector<Pos> m_Form;
};

#endif // TETRIMINO_H
