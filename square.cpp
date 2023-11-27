#include "square.h"

Square::Square(QWidget *parent, QColor color, int size) :
    QWidget(parent), color(color), sizepx(size), piece('-')
{
    QPalette pal = Square::palette();
    pal.setColor(QPalette::Background, color);
    setAutoFillBackground(true);
    setPalette(pal);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(sizepx, sizepx);
}

void Square::setPiece(char p)
{
    piece = p;
}

void Square::setColor(QColor color)
{
    this->color = color;
}

void Square::setSize(int size)
{
    this->sizepx = size;
}

int Square::getSize() const
{
    return this->sizepx;
}

char Square::getPiece() const
{
    return this -> piece;
}

void Square::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    if(piece != '-')
    {
        QPixmap pix;
        switch(piece)
        {
            case'p':
                pix.load(":/img/blackPawn.png");
                break;

            case 'b':
                pix.load(":/img/blackBishop.png");
                break;

            case 'n':
                pix.load(":/img/blackKnight.png");
                break;
            case 'r':
                pix.load(":/img/blackRook.png");
                break;

            case 'q':
                pix.load(":/img/blackQueen.png");
                break;
            case 'k':
                pix.load(":/img/blackKing.png");
                break;
            case 'P':
                pix.load(":/img/whitePawn.png");
                break;

            case 'B':
                pix.load(":/img/whiteBishop.png");
                break;

            case 'N':
                pix.load(":/img/whiteKnight.png");
                break;
            case 'R':
                pix.load(":/img/whiteRook.png");
                break;

            case 'Q':
                pix.load(":/img/whiteQueen.png");
                break;
            case 'K':
                pix.load(":/img/whiteKing.png");
                break;
        }
        painter.drawPixmap(rect(), pix.scaled(rect().size(),
                                    Qt::KeepAspectRatio));
    }
    else
    {
        QPalette pal = Square::palette();
        pal.setColor(QPalette::Background, color);
        setAutoFillBackground(true);
        setPalette(pal);
    }
}
