#ifndef GAMEMANEGER_H
#define GAMEMANEGER_H

#include "DataDefine.h"
#include "TetrisField.h"
#include "MyselfTetrimino.h"
#include "TetriminoFactory.h"
#include "TetriminoCreateNormal.h"
#include "TetriminoCreateDifficult.h"

#include <vector>
#include <memory>

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
    TetriminoFactory* _tetriminoFactory = new TetriminoCreateDifficult();
    MyselfTetrimino _myBlock;
    TetrisField _field;

    static const int s_intvalTime = 200;  // ここを大きくすると落ちる速度が低下
    int _freeFallCnt = -s_intvalTime;
    int _deleteLineCnt = 0;
    static const int s_levelUpVal = 4;

public:
    std::vector<Block> GetField() const;
    std::vector<Block> GetCtrlBlock() const;
    std::vector<Block> GetNextBlock() const;
    std::vector<Block> GetCtrlGhostBlock() const;
    double GetDetailPos() const;
    int GetDeleteLineCnt() const;
    int GetLevel() const;

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

    void SetDifficultMode();
    void SetNormalMode();
private:
    bool CanMoveTetrimino(const Pos& movePos) const;
    void DecisionMyTetrimino();
};

#endif // GAMEMANEGER_H
