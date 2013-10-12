#include "Dialog.h"
#include "ui_Dialog.h"

#include "DataDefine.h"

#include <QtGui>
#include <QtCore>
#include <QMessageBox>

Dialog::Dialog(StateMode *state, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    _timer(new QTimer()),
    _state(state),
    _bgPixmap(new QPixmap(":/new/BGA/bg.jpg"))
{
    ui->setupUi(this);
    _dispColorConfig[-1] = {Qt::white, Qt::lightGray, Qt::gray};
    _dispColorConfig[1] = {Qt::white, Qt::cyan, Qt::darkCyan};
    _dispColorConfig[2] = {Qt::white, Qt::blue, Qt::darkBlue};
    _dispColorConfig[3] = {Qt::white, {243, 152, 0}, {255, 140, 0}};
    _dispColorConfig[4] = {Qt::white, Qt::yellow, Qt::darkYellow};
    _dispColorConfig[5] = {Qt::white, Qt::green, Qt::darkGreen};
    _dispColorConfig[6] = {Qt::white, Qt::magenta, Qt::darkMagenta};
    _dispColorConfig[7] = {Qt::white, Qt::red, Qt::darkRed};
    _dispColorConfig[8] = {Qt::white, Qt::white, Qt::white};

    connect(_timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    _timer->start(s_timer);
}

Dialog::~Dialog()
{
    delete ui;
}

void
Dialog::paintEvent(QPaintEvent *e)
{
    ui->_scoreLCDNumber->display(_info.GetDeleteLineCnt());
    ui->_levelLCDNumber->display(_info.GetLevel());
    DrawBackGround();
    DrawWall();
    DrawField();
    DrawCtrlBlock();
    DrawNextBlock();
    DrawCtrlGhostBlock();
}

void
Dialog::keyPressEvent(QKeyEvent *e)
{
    _state = _state->CommandExecute(e);
}

void
Dialog::DrawBackGround()
{
    QPainter painter(this);
    QRect rect;
    rect.setSize(this->size());
    painter.drawPixmap(rect, *_bgPixmap);
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

    const auto wallData = _info.GetWallData();
    for(const auto block : wallData)
    {
        gradient.setColorAt(0.0, _dispColorConfig[block.id].startColor);
        gradient.setColorAt(0.7, _dispColorConfig[block.id].centerColor);
        gradient.setColorAt(1.0, _dispColorConfig[block.id].endColor);
        painter.setBrush(gradient);//グラデーションをブラシにセット
        painter.setOpacity(0.2);

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

    const auto fieldData = _info.GetFieldData();
    for(const auto block : fieldData)
    {
        gradient.setColorAt(0.0, _dispColorConfig[block.id].startColor);
        gradient.setColorAt(0.7, _dispColorConfig[block.id].centerColor);
        gradient.setColorAt(1.0, _dispColorConfig[block.id].endColor);
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

    const auto blocksData = _info.GetCtrlBlockData();
    const int detailPosY = static_cast<int>(_info.GetDetailPos() * s_bSz);
    for(const auto block : blocksData)
    {
        gradient.setColorAt(0.0, _dispColorConfig[block.id].startColor);
        gradient.setColorAt(0.7, _dispColorConfig[block.id].centerColor);
        gradient.setColorAt(1.0, _dispColorConfig[block.id].endColor);
        painter.setBrush(gradient);//グラデーションをブラシにセット
        const Pos pos = block.p;
        const int px = pos.posX * s_bSz + s_orgPx;
        const int py = pos.posY * s_bSz + detailPosY;
        painter.setBrushOrigin(px, py);
        painter.drawRect(px, py, s_bSz, s_bSz);
    }
}

void
Dialog::DrawNextBlock()
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    //アンチエイリアスセット
    painter.setRenderHint(QPainter::Antialiasing, true);

    //線形グラデ
    QLinearGradient gradient(0, 0, s_bSz, s_bSz);

    const auto blocksData = _info.GetNextBlockData();
    for(const auto block : blocksData)
    {
        gradient.setColorAt(0.0, _dispColorConfig[block.id].startColor);
        gradient.setColorAt(0.7, _dispColorConfig[block.id].centerColor);
        gradient.setColorAt(1.0, _dispColorConfig[block.id].endColor);
        painter.setBrush(gradient);//グラデーションをブラシにセット
        const Pos pos = block.p;
        const int px = pos.posX * s_bSz + s_nextOrgPx;
        const int py = pos.posY * s_bSz + s_nextOrgPy;
        painter.setBrushOrigin(px, py);
        painter.drawRect(px, py, s_bSz, s_bSz);
    }
}

void
Dialog::DrawCtrlGhostBlock()
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    //アンチエイリアスセット
    painter.setRenderHint(QPainter::Antialiasing, true);

    //線形グラデ
    QLinearGradient gradient(0, 0, s_bSz, s_bSz);

    const auto blocksData = _info.GetCtrlGhostBlockData();
    for(const auto block : blocksData)
    {
        gradient.setColorAt(0.0, _dispColorConfig[block.id].startColor);
        gradient.setColorAt(0.7, _dispColorConfig[block.id].centerColor);
        gradient.setColorAt(1.0, _dispColorConfig[block.id].endColor);
        painter.setBrush(gradient);//グラデーションをブラシにセット
        painter.setOpacity(block.alpha);
        const Pos pos = block.p;
        const int px = pos.posX * s_bSz + s_orgPx;
        const int py = pos.posY * s_bSz;
        painter.setBrushOrigin(px, py);
        painter.drawRect(px, py, s_bSz, s_bSz);
    }
}

void
Dialog::OnTimer()
{
    const bool isGameOver = !_state->NotifyUpdate();
    if(isGameOver)
    {
        _timer->stop();
        if(QMessageBox::Yes ==
           QMessageBox::question(this, "MyTetris GameOver", tr("GAMSEOVER\n\ngame again ?"),
           QMessageBox::Yes | QMessageBox::No))
        {
            Restart();
        }
        else
        {
            qApp->quit();
        }
    }
    update(); // paintEvent関数を呼び出す
}

void
Dialog::Restart()
{
    _timer->start(s_timer);
    _state->Restart();
}
