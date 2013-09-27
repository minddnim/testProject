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

void
Controller::NotifyUpdate()
{
    GameManeger::GetInstance()->Update();
}
