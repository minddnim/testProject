#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <vector>
#include "DataDefine.h"

class Tetrimino
{
public:
    Tetrimino(ColorID cid, const std::vector<Pos>& form)
            : m_colorID(cid)
            , m_form(form)
    {}
    virtual ~Tetrimino(){}

    const std::vector<Pos>& GetTetriminoForm() const
    {
        return m_form;
    }

    ColorID GetBlockColorID() const
    {
        return m_colorID;
    }

protected:
    const ColorID m_colorID;
    const std::vector<Pos> m_form;
};

#endif // TETRIMINO_H
