#ifndef STATEPLAYMODE_H
#define STATEPLAYMODE_H

#include "StateMode.h"

class QKeyEvent;

class StatePlayMode : public StateMode
{
private:
    StatePlayMode(){}

    StatePlayMode(const StatePlayMode& rhs);
    StatePlayMode& operator=(const StatePlayMode& rhs);

public:
    ~StatePlayMode(){}

    static StatePlayMode* GetInstance()
    {
        static StatePlayMode ins;
        return &ins;
    }

    bool NotifyUpdate();
    virtual StateMode* CommandExecute(QKeyEvent *e);
};

#endif // STATEPLAYMODE_H
