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
    TetriminoCreateNormal _tetriminoFactory;
    MyselfTetrimino _myBlock;
    TetrisField _field;

    static const int s_intvalTime = 200;  // ここを大きくすると落ちる速度が低下
    int _freeFallCnt = -s_intvalTime;

public:
    std::vector<Block> GetField() const;
    std::vector<Block> GetCtrlBlock() const;
    std::vector<Block> GetCtrlGhostBlock() const;
    double GetDetailPos() const;

    void GameStart();
    bool IsGameOver();
    void Initialize();
    bool Update();
    void UpdateGhostPos();

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
