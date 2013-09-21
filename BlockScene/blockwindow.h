#ifndef BLOCKWINDOW_H
#define BLOCKWINDOW_H

#include <QWidget>
#include "blockscene.h"

namespace Ui {
class BlockWindow;
}

class QLCDNumber;
class QPushButton;

class BlockWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BlockWindow(QWidget *parent = 0);
    ~BlockWindow();

public slots:
    void ballLoss();            // ボールをパッドで打ち損なった場合
    void hitBlock();            // ブロック消去した場合
    void restart();             // 再ゲーム
    void ballReleased();        // ボールリリース
    void onPlayPause(bool);     // [Play/Pause/ ボタン

private:
    Ui::BlockWindow *ui;
    BlockScene *m_blockScene;
    QTimer *m_timer;            // タイマーオブジェクト

    int m_score;                        // スコア
    int m_ballLeft;                     // 残りボール数
    QLCDNumber *m_scoreLCD;             // スコア
    QLCDNumber *m_ballLeftLCD;          // 残りボール数
    QPushButton *m_playPauseButton;     // play/Pause ボタン

    static const int TIMER = 2;
};

#endif // BLOCKWINDOW_H
