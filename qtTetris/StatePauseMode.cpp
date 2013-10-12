#include "StatePauseMode.h"
#include "StatePlayMode.h"
#include "qevent.h"

bool
StatePauseMode::NotifyUpdate()
{
    return true;
}

StateMode*
StatePauseMode::CommandExecute(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_Space:
        return StatePlayMode::GetInstance();
    default:
        break;
    }
    return this;
}
