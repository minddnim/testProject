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

    m_dispColorConfig[-1] = {Qt::white, Qt::lightGray, Qt::gray};
    m_dispColorConfig[1] = {Qt::white, Qt::cyan, Qt::darkCyan};
    m_dispColorConfig[2] = {Qt::white, Qt::blue, Qt::darkBlue};
    m_dispColorConfig[3] = {Qt::white, {243, 152, 0}, {255, 140, 0}};
    m_dispColorConfig[4] = {Qt::white, Qt::yellow, Qt::darkYellow};
    m_dispColorConfig[5] = {Qt::white, Qt::green, Qt::darkGreen};
    m_dispColorConfig[6] = {Qt::white, Qt::magenta, Qt::darkMagenta};
    m_dispColorConfig[7] = {Qt::white, Qt::red, Qt::darkRed};

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
Dialog::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_A:
        m_ctrl.KeyPress_A();
        break;
    case Qt::Key_S:
        m_ctrl.KeyPress_S();
        break;
    case Qt::Key_D:
        m_ctrl.KeyPress_D();
        break;
    case Qt::Key_W:
        m_ctrl.KeyPress_W();
        break;
    case Qt::Key_Left:
        m_ctrl.KeyPress_Left();
        break;
    case Qt::Key_Right:
        m_ctrl.KeyPress_Right();
        break;
    default:
        break;
    }
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

    const auto wallData = m_info.GetWallData();
    for(const auto block : wallData)
    {
        gradient.setColorAt(0.0, m_dispColorConfig[block.id].startColor);
        gradient.setColorAt(0.7, m_dispColorConfig[block.id].centerColor);
        gradient.setColorAt(1.0, m_dispColorConfig[block.id].endColor);
        painter.setBrush(gradient);//グラデーションをブラシにセット

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

    const auto wallData = m_info.GetFieldData();
    for(const auto block : wallData)
    {
        gradient.setColorAt(0.0, m_dispColorConfig[block.id].startColor);
        gradient.setColorAt(0.7, m_dispColorConfig[block.id].centerColor);
        gradient.setColorAt(1.0, m_dispColorConfig[block.id].endColor);
        painter.setBrush(gradient);//グラデーションをブラシにセット

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

    const auto wallData = m_info.GetCtrlBlockData();
    const int detailPosY = static_cast<int>(m_info.GetDetailPos() * s_bSz);
    for(const auto block : wallData)
    {
        gradient.setColorAt(0.0, m_dispColorConfig[block.id].startColor);
        gradient.setColorAt(0.7, m_dispColorConfig[block.id].centerColor);
        gradient.setColorAt(1.0, m_dispColorConfig[block.id].endColor);
        painter.setBrush(gradient);//グラデーションをブラシにセット

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
