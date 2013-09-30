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
    QLCDNumber *_levelLCDNumber;
    QLabel *_nextLabel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 520);
        Dialog->setMinimumSize(QSize(400, 520));
        Dialog->setMaximumSize(QSize(400, 520));
        _scoreLCDNumber = new QLCDNumber(Dialog);
        _scoreLCDNumber->setObjectName(QStringLiteral("_scoreLCDNumber"));
        _scoreLCDNumber->setGeometry(QRect(290, 188, 91, 23));
        QFont font;
        font.setPointSize(9);
        _scoreLCDNumber->setFont(font);
        _scoreLCDNumber->setSmallDecimalPoint(true);
        _scoreLCDNumber->setMode(QLCDNumber::Dec);
        _scoreLCDNumber->setSegmentStyle(QLCDNumber::Outline);
        _scoreLabel = new QLabel(Dialog);
        _scoreLabel->setObjectName(QStringLiteral("_scoreLabel"));
        _scoreLabel->setGeometry(QRect(290, 170, 61, 16));
        QPalette palette;
        QBrush brush(QColor(255, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        _scoreLabel->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\343\203\241\343\202\244\343\203\252\343\202\252"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        _scoreLabel->setFont(font1);
        _scoreLabel->setFrameShape(QFrame::NoFrame);
        _scoreLabel->setFrameShadow(QFrame::Plain);
        _scoreLabel->setLineWidth(1);
        _levelLabel = new QLabel(Dialog);
        _levelLabel->setObjectName(QStringLiteral("_levelLabel"));
        _levelLabel->setGeometry(QRect(290, 248, 61, 16));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        _levelLabel->setPalette(palette1);
        _levelLabel->setFont(font1);
        _levelLabel->setFrameShape(QFrame::NoFrame);
        _levelLabel->setFrameShadow(QFrame::Plain);
        _levelLabel->setLineWidth(1);
        _levelLCDNumber = new QLCDNumber(Dialog);
        _levelLCDNumber->setObjectName(QStringLiteral("_levelLCDNumber"));
        _levelLCDNumber->setGeometry(QRect(290, 268, 91, 23));
        _levelLCDNumber->setSmallDecimalPoint(true);
        _levelLCDNumber->setMode(QLCDNumber::Dec);
        _levelLCDNumber->setSegmentStyle(QLCDNumber::Outline);
        _levelLCDNumber->setProperty("intValue", QVariant(1));
        _nextLabel = new QLabel(Dialog);
        _nextLabel->setObjectName(QStringLiteral("_nextLabel"));
        _nextLabel->setGeometry(QRect(290, 20, 61, 16));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        _nextLabel->setPalette(palette2);
        _nextLabel->setFont(font1);
        _nextLabel->setFrameShape(QFrame::NoFrame);
        _nextLabel->setFrameShadow(QFrame::Plain);
        _nextLabel->setLineWidth(1);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "My Tetris", 0));
        _scoreLabel->setText(QApplication::translate("Dialog", "SCORE:", 0));
        _levelLabel->setText(QApplication::translate("Dialog", "LEVEL:", 0));
        _nextLabel->setText(QApplication::translate("Dialog", "NEXT:", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
