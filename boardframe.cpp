#include "boardframe.h"
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QPainterPath>

const unsigned int LINE = 19;

BoardFrame::BoardFrame(QWidget *parent)
    : QFrame(parent), player (Player::BLACK), board(LINE, std::vector<Stone>(LINE, Stone::NONE)), wstone(":/images/Go_w_no_bg.png"),
      bstone(":/images/Go_b_no_bg.png")
{
    setMinimumSize(200, 200);
    int imgSize = GAP * 0.7;
}

void BoardFrame::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    drawBoard();
    drawStones();
}

void BoardFrame::drawBoard()
{
    std::vector<std::pair<unsigned, unsigned>> pos {
        {3, 3}, {9, 3}, {15, 3},
        {3, 9}, {9, 9}, {15, 9},
        {3, 15}, {9, 15}, {15, 15}
    };

    QPainter painter(this);
    QPen pen(Qt::black, 1.5); // 검정색 선, 두께: 2
    painter.setPen(pen);

    unsigned int cp = TOP;

    for (int i = 0; i < LINE; i++)
    {
        painter.drawLine(LEFT, cp, RIGHT, cp);
        cp += GAP;
    }

    cp = LEFT;
    for (int i = 0; i < LINE; i++)
    {
        painter.drawLine(cp, TOP, cp, BOTTOM);
        cp += GAP;
    }

    QBrush brush(Qt::black, Qt::SolidPattern);
    painter.setBrush(brush);

    for (auto [x, y]:pos)
    {
        painter.drawEllipse(QPoint(LEFT + x * GAP, TOP + y * GAP), RADIUS, RADIUS);
    }

}

void BoardFrame::drawStones()
{
    QPainter painter(this);

    for (int y = 0; y < LINE; y++)
    {
        for (int x = 0; x < LINE; x++)
        {
            QPixmap stone;
            if (board[y][x] == Stone::WHITE)
                stone = wstone;
            else if (board[y][x] == Stone::BLACK)
                stone = bstone;
            else
                continue;

            int tx = LEFT + x * GAP - (IMGSIZE / 2);
            int ty = TOP + y * GAP - (IMGSIZE / 2);
            QRect rect(tx, ty, IMGSIZE, IMGSIZE);

            painter.drawPixmap(rect, stone);
        }
    }
}

void BoardFrame::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QPoint local = event->pos();

        int sx = local.x() - GAP / 2, sy = local.y() - GAP / 2;
        sx /= GAP;
        sy /= GAP;

        if (board[sy][sx] == Stone::NONE)
        {
            if (player == Player::BLACK)
            {
                board[sy][sx] = Stone::BLACK;
                player = Player::WHITE;
            }
            else
            {
                board[sy][sx] = Stone::WHITE;
                player = Player::BLACK;
            }

            repaint();
        }
    }
}

QPixmap BoardFrame::maskedEllipseImage(const QPixmap& source, const QSize& size)
{
    QPixmap result(size);
    result.fill(Qt::transparent); // 배경 투명하게

    QPainter painter(&result);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addEllipse(result.rect());
    painter.setClipPath(path);

    painter.drawPixmap(result.rect(), source);
    return result;
}
