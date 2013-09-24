#include "Controller.h"
#include "GameManeger.h"

void
Controller::GameStart()
{
    GameManeger::GetInstance()->GameStart();
}

void
Controller::NotifyUpdate()
{
    GameManeger::GetInstance()->update();
}
