#ifndef BOARDFRAME_H
#define BOARDFRAME_H

#include <QFrame>
#include <vector>

enum class Player { BLACK, WHITE };
enum class Stone { NONE, BLACK, WHITE };

class BoardFrame : public QFrame
{
    Q_OBJECT
public:
    explicit BoardFrame(QWidget *parent = nullptr);
    void drawBoard();
    void drawStones();
    void mousePressEvent(QMouseEvent *event) override;
protected:
    void paintEvent(QPaintEvent *event) override;
    std::vector<std::vector<Stone>> board;

    QPixmap maskedEllipseImage(const QPixmap& source, const QSize& size);
protected:
    const unsigned int GAP = 30;
    const unsigned int LEFT = 30;
    const unsigned int RIGHT = LEFT + GAP * 18;
    const unsigned int TOP = 30;
    const unsigned int BOTTOM = TOP + GAP * 18;
    const unsigned int RADIUS = 3;
    const unsigned int MARGIN = GAP / 2;
    const unsigned int IMGSIZE = GAP * 0.7;

    QPixmap wstone;
    QPixmap bstone;

    Player player;
};

#endif // BOARDFRAME_H
