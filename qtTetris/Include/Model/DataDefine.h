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
    explicit Block(const Pos& pos, ColorID clrId)
        : p(pos)
        , id(clrId){}
    Pos p;
    ColorID id;
};

#endif // DATADEFINE_H
