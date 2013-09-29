/********************************************************************************
** Form generated from reading UI file 'Dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLCDNumber *_scoreLCDNumber;
    QLabel *_scoreLabel;
    QLabel *_levelLabel;
    QLCDNumber *_LevelLCDNumber;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 520);
        Dialog->setMinimumSize(QSize(400, 520));
        Dialog->setMaximumSize(QSize(400, 520));
        _scoreLCDNumber = new QLCDNumber(Dialog);
        _scoreLCDNumber->setObjectName(QStringLiteral("_scoreLCDNumber"));
        _scoreLCDNumber->setGeometry(QRect(320, 30, 64, 23));
        _scoreLCDNumber->setSmallDecimalPoint(true);
        _scoreLCDNumber->setMode(QLCDNumber::Dec);
        _scoreLCDNumber->setSegmentStyle(QLCDNumber::Outline);
        _scoreLabel = new QLabel(Dialog);
        _scoreLabel->setObjectName(QStringLiteral("_scoreLabel"));
        _scoreLabel->setGeometry(QRect(320, 12, 61, 16));
        QPalette palette;
        QBrush brush(QColor(255, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        _scoreLabel->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\343\203\241\343\202\244\343\203\252\343\202\252"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        _scoreLabel->setFont(font);
        _scoreLabel->setFrameShape(QFrame::NoFrame);
        _scoreLabel->setFrameShadow(QFrame::Plain);
        _scoreLabel->setLineWidth(1);
        _levelLabel = new QLabel(Dialog);
        _levelLabel->setObjectName(QStringLiteral("_levelLabel"));
        _levelLabel->setGeometry(QRect(320, 90, 61, 16));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        _levelLabel->setPalette(palette1);
        _levelLabel->setFont(font);
        _levelLabel->setFrameShape(QFrame::NoFrame);
        _levelLabel->setFrameShadow(QFrame::Plain);
        _levelLabel->setLineWidth(1);
        _LevelLCDNumber = new QLCDNumber(Dialog);
        _LevelLCDNumber->setObjectName(QStringLiteral("_LevelLCDNumber"));
        _LevelLCDNumber->setGeometry(QRect(320, 110, 64, 23));
        _LevelLCDNumber->setSmallDecimalPoint(true);
        _LevelLCDNumber->setMode(QLCDNumber::Dec);
        _LevelLCDNumber->setSegmentStyle(QLCDNumber::Outline);
        _LevelLCDNumber->setProperty("intValue", QVariant(1));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "My Tetris", 0));
        _scoreLabel->setText(QApplication::translate("Dialog", "SCORE:", 0));
        _levelLabel->setText(QApplication::translate("Dialog", "LEVEL:", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
