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
    void NotifyUpdate();
};

#endif // CONTROLLER_H
