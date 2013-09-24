#include "Dialog.h"
#include "ui_Dialog.h"

#include "DataDefine.h"

#include <QtGui>
#include <QtCore>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    m_timer->start(TIMER);

    m_ctrl.GameStart();
}

Dialog::~Dialog()
{
    delete ui;
}

void
Dialog::paintEvent(QPaintEvent *e)
{
    DrawWall();
    DrawField();
    DrawCtrlBlock();
}

void
Dialog::DrawWall()
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

    const auto wallData = m_info.GetWallData();
    for(const auto block : wallData)
    {
        const Pos pos = block.p;
        const int px = pos.posX * s_bSz + s_orgPx;
        const int py = pos.posY * s_bSz + s_orgPy;
        painter.setBrushOrigin(px, py);
        painter.drawRect(px, py, s_bSz, s_bSz);
    }
}

void
Dialog::DrawField()
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    //アンチエイリアスセット
    painter.setRenderHint(QPainter::Antialiasing, true);

    //線形グラデ
    QLinearGradient gradient(0, 0, s_bSz, s_bSz);
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(0.7, Qt::yellow);
    gradient.setColorAt(1.0, Qt::darkYellow);

    painter.setBrush(gradient);//グラデーションをブラシにセット

    const auto wallData = m_info.GetFieldData();
    for(const auto block : wallData)
    {
        const Pos pos = block.p;
        const int px = pos.posX * s_bSz + s_orgPx;
        const int py = pos.posY * s_bSz;
        painter.setBrushOrigin(px, py);
        painter.drawRect(px, py, s_bSz, s_bSz);
    }
}

void
Dialog::DrawCtrlBlock()
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    //アンチエイリアスセット
    painter.setRenderHint(QPainter::Antialiasing, true);

    //線形グラデ
    QLinearGradient gradient(0, 0, s_bSz, s_bSz);
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(0.7, Qt::magenta);
    gradient.setColorAt(1.0, Qt::darkMagenta);

    painter.setBrush(gradient);//グラデーションをブラシにセット

    const auto wallData = m_info.GetCtrlBlockData();
    const int detailPosY = static_cast<int>(m_info.GetDetailPos() * s_bSz);
    for(const auto block : wallData)
    {
        const Pos pos = block.p;
        const int px = pos.posX * s_bSz + s_orgPx;
        const int py = pos.posY * s_bSz + detailPosY;
        painter.setBrushOrigin(px, py);
        painter.drawRect(px, py, s_bSz, s_bSz);
    }
}

void
Dialog::OnTimer()
{
    m_ctrl.NotifyUpdate();
    update(); // paintEvent関数を呼び出す
}
