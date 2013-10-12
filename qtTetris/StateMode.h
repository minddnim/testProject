#ifndef STATEMODE_H
#define STATEMODE_H

#include "Controller.h"

class QKeyEvent;

class StateMode
{
public:
    StateMode(){}
    virtual ~StateMode(){}

    void Restart(){_ctrl.Restart();}

    virtual bool NotifyUpdate() = 0;
    virtual StateMode* CommandExecute(QKeyEvent *e) = 0;

protected:
    Controller _ctrl;
};

#endif // STATEMODE_H
