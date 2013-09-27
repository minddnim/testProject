#ifndef DIALOG_H
#define DIALOG_H

#include "ConvDispInfo.h"
#include "Controller.h"

#include <QDialog>
#include <vector>
#include <map>

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

    QTimer *_timer;            // タイマーオブジェクト
    static const int TIMER = 1;

    ConvDispInfo _info;
    Controller _ctrl;

    struct SetColors
    {
        QColor startColor;
        QColor centerColor;
        QColor endColor;
    };
    std::map<ColorID, SetColors> _dispColorConfig;

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);

public slots:
    void OnTimer();

private:
    void DrawWall();
    void DrawField();
    void DrawCtrlBlock();
    void DrawCtrlGhostBlock();
};

#endif // DIALOG_H
