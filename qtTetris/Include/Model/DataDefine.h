#ifndef DATADEFINE_H
#define DATADEFINE_H

struct Pos
{
    int posX;
    int posY;
};

typedef int ColorID;

struct Block
{
    explicit Block(const Pos& pos, ColorID clrId, double alphaVal = 1.0)
        : p(pos)
        , id(clrId)
        , alpha(alphaVal)
    {}

    Pos p;
    ColorID id;
    double alpha;
};

#endif // DATADEFINE_H
