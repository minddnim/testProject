#ifndef DIALOG_H
#define DIALOG_H

#include "ConvDispInfo.h"
#include "Controller.h"

#include <QDialog>
#include <vector>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    static const int s_orgPx = 50;
    static const int s_orgPy = 80;
    static const int s_bSz = 20;

    QTimer *m_timer;            // タイマーオブジェクト
    static const int TIMER = 1;

    ConvDispInfo m_info;
    Controller m_ctrl;

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);

public slots:
    void OnTimer();

private:
    void DrawWall();
    void DrawField();
    void DrawCtrlBlock();\
};

#endif // DIALOG_H
