#include "StatePauseMode.h"
#include "StatePlayMode.h"
#include "qevent.h"

bool
StatePlayMode::NotifyUpdate()
{
    return _ctrl.NotifyUpdate();
}

StateMode*
StatePlayMode::CommandExecute(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_A:
        _ctrl.KeyPress_A();
        break;
    case Qt::Key_S:
        _ctrl.KeyPress_S();
        break;
    case Qt::Key_D:
        _ctrl.KeyPress_D();
        break;
    case Qt::Key_W:
        _ctrl.KeyPress_W();
        break;
    case Qt::Key_J:
        _ctrl.KeyPress_Left();
        break;
    case Qt::Key_K:
        _ctrl.KeyPress_Right();
        break;
    case Qt::Key_Space:
        return StatePauseMode::GetInstance();
    default:
        break;
    }
    return this;
}

