#include "Dialog.h"
#include <QApplication>
#include <QMessageBox>
#include <memory>

#include "GameManeger.h"
#include "StateMode.h"
#include "StatePlayMode.h"

void SelectMode(bool isDifficultMode)
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

void Initialize(Dialog& w)
{
//    const bool isDifficultMode =
//            QMessageBox::Yes == QMessageBox::question(&w, "Mode select", "Do you play DifficultMode?",
//                                  QMessageBox::Yes | QMessageBox::No);
    const bool isDifficultMode = false;
    SelectMode(isDifficultMode);
    GameManeger::GetInstance()->GameStart();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w(StatePlayMode::GetInstance());
    Initialize(w);
    w.show();
    return a.exec();
}
