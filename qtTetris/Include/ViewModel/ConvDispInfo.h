#ifndef CONVDISPINFO_H
#define CONVDISPINFO_H

#include "DataDefine.h"
#include <vector>

class ConvDispInfo
{
public:
    ConvDispInfo();
    ~ConvDispInfo(){}

private:
    static const ColorID s_blockColorID = -1;
    static const int s_fldH = 20;
    static const int s_fldW = 10;
    std::vector<Block> _blockWall;

public:
    std::vector<Block> GetWallData() const;
    std::vector<Block> GetFieldData() const;
    std::vector<Block> GetCtrlBlockData() const;
    std::vector<Block> GetCtrlGhostBlockData() const;
    double GetDetailPos() const;
};

#endif // CONVDISPINFO_H
