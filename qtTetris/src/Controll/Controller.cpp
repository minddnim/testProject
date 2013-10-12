#include "Controller.h"
#include "GameManeger.h"

void
Controller::GameStart()
{
    GameManeger::GetInstance()->GameStart();
}

void
Controller::KeyPress_A()
{
    GameManeger::GetInstance()->TryMoveLeft();
}

void
Controller::KeyPress_S()
{
    GameManeger::GetInstance()->TryMoveDown();
}

void
Controller::KeyPress_D()
{
    GameManeger::GetInstance()->TryMoveRight();
}

void
Controller::KeyPress_W()
{
    GameManeger::GetInstance()->TryMoveButtom();
}

void
Controller::KeyPress_Right()
{
    GameManeger::GetInstance()->TryRotateRight();
}

void
Controller::KeyPress_Left()
{
    GameManeger::GetInstance()->TryRotateLeft();
}

bool
Controller::NotifyUpdate()
{
    return GameManeger::GetInstance()->Update();
}

void
Controller::Restart()
{
    GameManeger::GetInstance()->Initialize();
}

void
Controller::SelectMode(bool isDifficultMode)
{
    if(isDifficultMode)
    {
        GameManeger::GetInstance()->SetDifficultMode();
    }
    else
    {
        GameManeger::GetInstance()->SetNormalMode();
    }
}
