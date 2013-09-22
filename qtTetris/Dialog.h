#ifndef DIALOG_H
#define DIALOG_H

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
    static const int s_orgPx = 10;
    static const int s_orgPy = 70;
    static const int s_bSz = 20;
    static const int s_fldH = 20;
    static const int s_fldW = 10;
    std::vector<QRect> m_blockWall;

protected:
    void paintEvent(QPaintEvent *e);

private:
    void DrawWall();
};

#endif // DIALOG_H
