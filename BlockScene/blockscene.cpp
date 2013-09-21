#include "blockscene.h"
#include <QtGui>
#include <QApplication>

BlockScene::BlockScene(QWidget *parent) :
    QWidget(parent),
    m_ballX(SCENE_WIDTH / 2),
    m_ballY(SCENE_HEIGHT - PAD_WIDTH - BALL_RADIUS),
    m_prevBallX(m_ballX),
    m_prevBallY(m_ballY),
    m_padX(SCENE_WIDTH / 2 - PAD_LENGTH / 2),
    m_ballVx(INIT_BALL_DX),
    m_ballVy(INIT_BALL_DY)
{
    for(int i = 0; i < N_ROW_BLOCK; ++i)
    {
        for(int k = 0; k < N_COLUMN_BLOCK; ++k)
        {
            m_block[i][k] = true;
        }
    }
}

void BlockScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect r = rect();

    // 壁部分描画
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, WALL_WIDTH, r.height());
    painter.drawRect(r.width() - WALL_WIDTH, 0, WALL_WIDTH, r.height());
    painter.drawRect(0, 0, r.width(), WALL_WIDTH);

    // ブロック部分描画
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing, true);//アンチエイリアスセット

    QLinearGradient gradient(0, 0, BLOCK_WIDTH, BLOCK_HEIGHT);//線形グラデ
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(0.8, Qt::yellow);
    gradient.setColorAt(1.0, Qt::yellow);

    painter.setBrush(gradient);//グラデーションをブラシにセット

    int y = BLOCK_Y;
    for(int i = 0; i < N_ROW_BLOCK; ++i)
    {
        int x = WALL_WIDTH;
        for(int k = 0; k < N_COLUMN_BLOCK; ++k)
        {
            if(m_block[i][k])                   // ブロックが有る場合
            {
                painter.setBrushOrigin(x, y);
                painter.drawRect(x, y, BLOCK_WIDTH, BLOCK_HEIGHT);
            }
            x += BLOCK_WIDTH;
        }
        y += BLOCK_HEIGHT;
    }

    // ボール描画
    painter.setPen(Qt::black);
    painter.setBrush(Qt::green);
    painter.drawEllipse(m_ballX - BALL_RADIUS, m_ballY - BALL_RADIUS, BALL_RADIUS * 2, BALL_RADIUS * 2 );

    // パッド描画
    painter.setBrush(Qt::blue);
    painter.drawRect(m_padX, SCENE_HEIGHT - PAD_WIDTH, PAD_LENGTH, PAD_WIDTH);
}

void BlockScene::onTimer()
{
    iteratePad();       // パッド位置更新
    if(m_ballCatched)
    {
        m_ballX = m_padX + PAD_LENGTH / 2;
        m_ballY = SCENE_HEIGHT - PAD_WIDTH - BALL_RADIUS;
    }
    else
    {
        iterateBall();      // ボール移動処理
    }
    update();           // 画面無効化
}

void BlockScene::iterateBall()
{
    m_prevBallX = m_ballX;
    m_prevBallY = m_ballY;
    m_ballX += m_ballVx;    // ボール座標更新
    m_ballY += m_ballVy;
    if(!reflectByBlock())
    {
        reflectByWall();        // 壁による反射
    }
    reflectByPad();
}

void BlockScene::iteratePad()
{
    // パッドの位置更新
    m_padX = mapFromGlobal(QCursor::pos()).x() - PAD_LENGTH / 2;

    // パッドを画面左右端で止める
    if(m_padX < WALL_WIDTH)
    {
        m_padX = WALL_WIDTH;
    }
    else if(m_padX + PAD_LENGTH > SCENE_WIDTH - WALL_WIDTH)
    {
        m_padX = SCENE_WIDTH - WALL_WIDTH - PAD_LENGTH;
    }
}

bool BlockScene::IsCrushCelling() const
{
    const int wallPosY = WALL_WIDTH + BALL_RADIUS;
    return m_ballY < wallPosY;
}

bool BlockScene::IsCrushWallLeft() const
{
    const int wallPosX_Left = WALL_WIDTH + BALL_RADIUS;
    return m_ballX < wallPosX_Left;
}

bool BlockScene::IsCrushWallRight() const
{
    const int wallPosX_Right = SCENE_WIDTH - WALL_WIDTH - BALL_RADIUS;
    return m_ballX > wallPosX_Right;
}

void BlockScene::reflectByWall()
{
    // 上の壁による反射
    if(IsCrushCelling())
    {
        m_ballY = (WALL_WIDTH + BALL_RADIUS) * 2 - m_ballY;
        m_ballVy = -m_ballVy;
    }

    // 左右の壁による反射
    if(IsCrushWallLeft())
    {
        m_ballX = (WALL_WIDTH + BALL_RADIUS);
        m_ballVx = -m_ballVx;
    }
    else if(IsCrushWallRight())
    {
        m_ballX = (SCENE_WIDTH - WALL_WIDTH - BALL_RADIUS) * 2 - m_ballX;
        m_ballVx = -m_ballVx;
    }
}

void BlockScene::reflectByPad()
{
    if(m_ballY > SCENE_HEIGHT + BALL_RADIUS)
    {
        if(m_ballX >= m_padX && m_ballX <= m_padX + PAD_LENGTH)
        {
            // パッドに当たった場合(パッド端でのボール半径は無視)
            m_ballY = (SCENE_HEIGHT + BALL_RADIUS) * 2 - m_ballY;
            m_ballVy = -m_ballVy;
        }
        else
        {
            // ボールを逃した場合
            emit ballLoss();
        }
    }
}

int BlockScene::ConvertToColFromPosX(int posX) const
{
    return (posX - WALL_WIDTH)/BLOCK_WIDTH;
}

int BlockScene::ConvertToRowFromPosY(int posY) const
{
    return (posY - BLOCK_Y)/BLOCK_HEIGHT;
}

bool BlockScene::IsExistBlockNowPos() const
{
    const int ballPosCol = ConvertToColFromPosX(m_ballX);
    const int ballPosRow = ConvertToRowFromPosY(m_ballY);

    if(ballPosRow < 0 || N_ROW_BLOCK <= ballPosRow)
    {
        return false;
    }
    if(ballPosCol < 0 || N_COLUMN_BLOCK <= ballPosCol)
    {
        return false;
    }

    return m_block[ballPosRow][ballPosCol];
}

BlockScene::DIRECTION BlockScene::CrushDirection() const
{
    const int nowCol = ConvertToColFromPosX(m_ballX);
    const int nowRow = ConvertToRowFromPosY(m_ballY);

    const int prevCol = ConvertToColFromPosX(m_prevBallX);
    const int prevRow = ConvertToRowFromPosY(m_prevBallY);

    const int vecNPCol = prevCol - nowCol;
    const int vecNPRow = prevRow - nowRow;

    if(vecNPCol < 0  && vecNPRow > 0)   return DIR_LT;
    if(vecNPCol == 0 && vecNPRow > 0)   return DIR_T;
    if(vecNPCol > 0  && vecNPRow > 0)   return DIR_RT;
    if(vecNPCol < 0  && vecNPRow == 0)  return DIR_L;
    if(vecNPCol == 0 && vecNPRow == 0)  return DIR_;
    if(vecNPCol > 0  && vecNPRow == 0)  return DIR_R;
    if(vecNPCol < 0  && vecNPRow < 0)   return DIR_LB;
    if(vecNPCol == 0 && vecNPRow < 0)   return DIR_B;
    if(vecNPCol > 0  && vecNPRow < 0)   return DIR_RB;

    // ここには来ないはず
    return ERROR_;
}

bool BlockScene::reflectByBlock()
{
    if(!IsExistBlockNowPos())
    {
        return false;
    }

    const int c = ConvertToColFromPosX(m_ballX);
    const int r = ConvertToRowFromPosY(m_ballY);

    switch(CrushDirection())
    {
    case DIR_LT:
        m_ballVx = -m_ballVx;
        m_ballVy = -m_ballVy;
        break;
    case DIR_T:
        m_ballVy = -m_ballVy;
        break;
    case DIR_RT:
        m_ballVx = -m_ballVx;
        m_ballVy = -m_ballVy;
        break;
    case DIR_L:
        m_ballVx = -m_ballVx;
        break;
    case DIR_R:
        m_ballVx = -m_ballVx;
        break;
    case DIR_LB:
        m_ballVx = -m_ballVx;
        m_ballVy = -m_ballVy;
        break;
    case DIR_B:
        m_ballVy = -m_ballVy;
        break;
    case DIR_RB:
        m_ballVx = -m_ballVx;
        m_ballVy = -m_ballVy;
        break;
    case DIR_:
    case ERROR_:
    default:
        return false;
    }

    m_block[r][c] = false;
    emit hitBlock();
    return true;
}

void BlockScene::restart(bool resetBlock)
{
    m_ballCatched = true;
    if(resetBlock)
    {
        createBlock();
    }

    m_ballX = SCENE_WIDTH / 2;
    m_ballY = SCENE_HEIGHT - PAD_WIDTH - BALL_RADIUS;
    m_ballVx = INIT_BALL_DX;
    m_ballVy = INIT_BALL_DY;
    m_padX = SCENE_WIDTH / 2 - PAD_LENGTH / 2;
}

void BlockScene::createBlock()
{
    m_blockLeft = N_ROW_BLOCK * N_COLUMN_BLOCK;
    for(int i = 0; i < N_ROW_BLOCK; ++i)
    {
        for(int k = 0; k < N_COLUMN_BLOCK; ++k)
        {
            m_block[i][k] = true;
        }
    }
}

void BlockScene::mousePressEvent(QMouseEvent *event)
{
    if(m_ballCatched)
    {
        m_ballCatched = false;
        emit ballReleased();
    }
}



