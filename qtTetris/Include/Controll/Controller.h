#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "DataDefine.h"
#include <vector>

class Controller
{
public:
    Controller(){}
    ~Controller(){}

public:
    void GameStart();
    void KeyPress_A();
    void KeyPress_S();
    void KeyPress_D();
    void KeyPress_W();
    void KeyPress_Right();
    void KeyPress_Left();
    bool NotifyUpdate();
    void Restart();
};

#endif // CONTROLLER_H
