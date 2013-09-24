#ifndef GAMEMANEGER_H
#define GAMEMANEGER_H

#include "DataDefine.h"
#include "TetrisField.h"
#include "MyselfTetrimino.h"

#include <memory>
#include <vector>

class GameManeger
{
public:
    static GameManeger* GetInstance()
    {
        static GameManeger ins;
        return &ins;
    }
    ~GameManeger(){}

private:
    GameManeger()
        : m_freeFallCnt(0)
    {}

    GameManeger(const GameManeger& rhs);
    GameManeger& operator=(const GameManeger& rhs);

private:
    MyselfTetrimino m_myBlock;
    TetrisField m_field;

    int m_freeFallCnt;
    static const int s_intvalTime = 200;  // ここを大きくすると落ちる速度が低下

public:
    std::vector<Block> GetField() const;
    std::vector<Block> GetCtrlBlock() const;
    double GetDetailPos() const;

    void GameStart();
    void update();
    void FreeFall();
};

#endif // GAMEMANEGER_H
