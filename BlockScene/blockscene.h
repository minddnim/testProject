#ifndef BLOCKSCENE_H
#define BLOCKSCENE_H

#include <QWidget>

class BlockScene : public QWidget
{
    Q_OBJECT
public:
    explicit BlockScene(QWidget *parent = 0);

    enum {
        SCENE_WIDTH = 320,
        SCENE_HEIGHT = 480,
        WALL_WIDTH = 10,                                                // 壁の幅
        PAD_WIDTH = 4,                                                  // パッド厚さ
        PAD_LENGTH = 64,                                                // パッド長さ
        BALL_RADIUS = 4,                                                // ボール半径
        INIT_BALL_DX = 1,                                               // 初期ボール速度
        INIT_BALL_DY = -2,
        MAX_BALL_DX = 8,                                                // 最大ボール速度
        MIN_BALL_DX = -8,

        BLOCK_WIDTH = 30,                                               // ブロック幅
        BLOCK_HEIGHT = 10,                                              // ブロック高さ
        N_ROW_BLOCK = 6,                                                // ブロック段数
        N_COLUMN_BLOCK = (SCENE_WIDTH - WALL_WIDTH * 2) / BLOCK_WIDTH,  // １行のブロック個数
        N_ROW_SPACE = 3,                                                // 画面上部空白段数
        BLOCK_Y = WALL_WIDTH + N_ROW_SPACE * BLOCK_HEIGHT               // ブロック描画位置
    };

    enum DIRECTION
    {
        DIR_LT = 0,
        DIR_T,
        DIR_RT,
        DIR_L,
        DIR_,
        DIR_R,
        DIR_LB,
        DIR_B,
        DIR_RB,
        ERROR_
    };

public:
    QSize sizeHint() const
    {
        return QSize(SCENE_WIDTH, SCENE_HEIGHT);
    }

signals:
    void ballLoss();            // ボールを逃した場合
    void hitBlock();            // ブロック消去
    void ballReleased();

public slots:
    void onTimer();
    void restart(bool resetBlock = true);
    void onPlay() { m_ballCatched = false; }

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void iterateBall();
    void iteratePad();
    void reflectByWall();
    void reflectByPad();        // ボールをパッドで打った場合
    bool reflectByBlock();

    void createBlock();

private:
    bool IsCrushCelling() const;
    bool IsCrushWallLeft() const;
    bool IsCrushWallRight() const;
    bool IsExistBlockNowPos() const;

    int ConvertToColFromPosX(int posX) const;
    int ConvertToRowFromPosY(int posY) const;

    DIRECTION CrushDirection() const;

private:
    int m_ballX;                                                        // ボール中心座標
    int m_ballY;
    int m_prevBallX;
    int m_prevBallY;
    int m_padX;                                                         // パッド左端座標
    bool m_block[N_ROW_BLOCK][N_COLUMN_BLOCK];                          // true for ブロック有り
    int m_blockLeft;

    int m_ballVx;                                                       // ボール速度/20msec
    int m_ballVy;

    bool m_ballCatched;
};

#endif // BLOCKSCENE_H
