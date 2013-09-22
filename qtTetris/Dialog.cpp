#include "Dialog.h"
#include "ui_Dialog.h"

#include <QtGui>
#include <QtCore>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    // 左側面の壁の定義
    for(int i = 0; i < s_fldH; ++i)
        m_blockWall.push_back(QRect(s_orgPx, s_orgPy+s_bSz*i, s_bSz, s_bSz));

    // 底の壁の定義
    for(int i = 0; i < s_fldW+1; ++i)
        m_blockWall.push_back(QRect(s_orgPx+s_bSz*i, s_orgPy+s_bSz*s_fldH, s_bSz, s_bSz));

    // 右側面の壁の定義
    for(int i = 0; i < s_fldH; ++i)
        m_blockWall.push_back(QRect(s_orgPx+s_bSz*s_fldW, s_orgPy+s_bSz*i, s_bSz, s_bSz));

    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    DrawWall();
}

void Dialog::DrawWall()
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    //アンチエイリアスセット
    painter.setRenderHint(QPainter::Antialiasing, true);

    //線形グラデ
    QLinearGradient gradient(0, 0, s_bSz, s_bSz);
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(0.7, Qt::lightGray);
    gradient.setColorAt(1.0, Qt::gray);

    painter.setBrush(gradient);//グラデーションをブラシにセット

    for(auto r : m_blockWall)
    {
        painter.setBrushOrigin(r.x(), r.y());
        painter.drawRect(r.x(), r.y(), s_bSz, s_bSz);
    }
}
