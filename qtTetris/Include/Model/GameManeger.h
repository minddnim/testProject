#ifndef GAMEMANEGER_H
#define GAMEMANEGER_H

#include "DataDefine.h"
#include "TetrisField.h"
#include "MyselfTetrimino.h"
#include "TetriminoFactory.h"
#include "TetriminoCreateNormal.h"

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
    GameManeger(){}

    GameManeger(const GameManeger& rhs);
    GameManeger& operator=(const GameManeger& rhs);

private:
    TetriminoCreateNormal m_tetriminoFactory;
    MyselfTetrimino m_myBlock;
    TetrisField m_field;

    static const int s_intvalTime = 20;  // ここを大きくすると落ちる速度が低下
    int m_freeFallCnt = -s_intvalTime;

public:
    std::vector<Block> GetField() const;
    std::vector<Block> GetCtrlBlock() const;
    double GetDetailPos() const;

    void GameStart();
    void update();

    void TryRotateRight();
    void TryRotateLeft();
    void TryMoveRight();
    void TryMoveLeft();
    void TryMoveDown();
    void TryMoveButtom();

    void FreeFall();

private:
    bool CanMoveTetrimino(const Pos& movePos) const;
    void DecisionMyTetrimino();
};

#endif // GAMEMANEGER_H
