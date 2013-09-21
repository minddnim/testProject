#include "blockmain.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

BlockMain::BlockMain(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(new QLabel(tr("SCORE:")));
    vLayout->addWidget(m_scoreLCD = new QLCDNumber());
    vLayout->addStretch();
    vLayout->addWidget(m_playPauseButton = new QPushButton(tr("Play")));

    vLayout->addWidget(new QLabel(tr("Left:")));
    vLayout->addWidget(m_ballLeftLCD = new QLCDNumber());

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addLayout(vLayout);
    hLayout->addWidget(m_blockScene = new BlockScene());


    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()),
            m_blockScene, SLOT(onTimer()));

}

