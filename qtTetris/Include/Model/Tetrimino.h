#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <vector>
#include "DataDefine.h"

class Tetrimino
{
public:
    Tetrimino(ColorID cid, const std::vector<Pos>& form)
            : m_ColorID(cid)
            , m_Form(form)
    {}
    virtual ~Tetrimino(){}

    std::vector<Pos> GetTetriminoForm() const
    {
        return m_Form;
    }

protected:
    const ColorID m_ColorID;
    std::vector<Pos> m_Form;
};

#endif // TETRIMINO_H
