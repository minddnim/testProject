#include "blockwindow.h"
#include "ui_blockwindow.h"
#include <QtGui>
#include "blockwindow.h"
#include "blockscene.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QMessageBox>

BlockWindow::BlockWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlockWindow)
{
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(new QLabel(tr("SCORE:")));
    vLayout->addWidget(m_scoreLCD = new QLCDNumber());
    vLayout->addStretch();
    vLayout->addWidget(m_playPauseButton = new QPushButton(tr("Play")));

    m_playPauseButton->setCheckable(true);
    m_playPauseButton->setChecked(false);

    connect(m_playPauseButton, SIGNAL(toggled(bool)),
            this, SLOT(onPlayPause(bool)));

    vLayout->addWidget(new QLabel(tr("Left:")));
    vLayout->addWidget(m_ballLeftLCD = new QLCDNumber());

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addLayout(vLayout);
    hLayout->addWidget(m_blockScene = new BlockScene());
    hLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(hLayout);

    connect(m_blockScene, SIGNAL(ballLoss()),
            this, SLOT(ballLoss()));
    connect(m_blockScene, SIGNAL(hitBlock()),
            this, SLOT(hitBlock()));
    connect(m_blockScene, SIGNAL(ballReleased()),
            this, SLOT(ballReleased()));

    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), m_blockScene, SLOT(onTimer()));
    m_timer->start(TIMER);     // 20FPS

    restart();

    ui->setupUi(this);
}

BlockWindow::~BlockWindow()
{
    delete ui;
}

void BlockWindow::restart()
{
    m_timer->start(TIMER);
    m_score = 0;
    m_scoreLCD->display(m_score);
    m_ballLeft = 2;
    m_ballLeftLCD->display(m_ballLeft);
    update();
    m_blockScene->restart();
}

void BlockWindow::ballLoss()
{
    m_playPauseButton->setChecked(false);
    --m_ballLeft;
    m_ballLeftLCD->display(m_ballLeft);
    update();
    if(!m_ballLeft)
    {
        m_timer->stop();
        if(QMessageBox::Yes ==
           QMessageBox::question(this, "block", tr("GAMSEOVER\n\ngame again ?"),
           QMessageBox::Yes | QMessageBox::No))
        {
            restart();
        }
        else
        {
            qApp->quit();
        }
    }
    else
    {
        m_blockScene->restart(/* reset block = */ false);
    }
    m_timer->start(TIMER);
}

void BlockWindow::ballReleased()
{
    m_playPauseButton->setChecked(true);
}

void BlockWindow::onPlayPause(bool play)
{
    m_playPauseButton->setText(play ? tr("Pause") : tr("Play"));
    if(play)
    {
        m_blockScene->onPlay();
        m_timer->start(TIMER);
    }
    else
    {
        m_timer->stop();
    }
}

void BlockWindow::hitBlock()
{
    m_score += 10;
    m_scoreLCD->display(m_score);
}
