#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <vector>
#include "DataDefine.h"

class Tetrimino
{
public:
    Tetrimino(ColorID cid, const std::vector<Pos>& form)
            : _colorID(cid)
            , _form(form)
    {}
    virtual ~Tetrimino(){}

    const std::vector<Pos>& GetTetriminoForm() const
    {
        return _form;
    }

    ColorID GetBlockColorID() const
    {
        return _colorID;
    }

protected:
    const ColorID _colorID;
    const std::vector<Pos> _form;
};

#endif // TETRIMINO_H
