#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>
#include <QPainter>

class Square : public QWidget
{
    Q_OBJECT
public:
    explicit Square(QWidget *parent = nullptr, QColor color = Qt::white,int size = 100);
    void setColor(QColor color);
    void setPiece(char p);
    void setSize(int size);
    int getSize() const;
    char getPiece() const;
protected:
    void paintEvent(QPaintEvent *event);

signals:

private:
    QColor color;
    int sizepx;
    char piece;
};

#endif // SQUARE_H
