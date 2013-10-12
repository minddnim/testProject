#ifndef STATEPAUSEMODE_H
#define STATEPAUSEMODE_H

#include "StateMode.h"

class StatePauseMode : public StateMode
{
private:
    StatePauseMode(){}

    StatePauseMode(const StatePauseMode& rhs);
    StatePauseMode& operator=(const StatePauseMode& rhs);

public:
    ~StatePauseMode(){}

    static StatePauseMode* GetInstance()
    {
        static StatePauseMode ins;
        return &ins;
    }

    bool NotifyUpdate();
    virtual StateMode* CommandExecute(QKeyEvent *e);
};

#endif // STATEPAUSEMODE_H
