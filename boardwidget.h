#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include "square.h"
#include <QGridLayout>
#include <string>
#include <string.h>
#include <cstdlib>
#include <QTextStream>
#include <move.h>
#include "chesspiece.h"

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = nullptr);
    void readFen(std::string fen);
    void test();

signals:

private:
    static const int boardSize = 8;
    QColor white;
    QColor black;
    Square *sq[boardSize][boardSize];
    QGridLayout* layout;

    struct state
    {
        std::string piecePlacement;
        char activeColor;
        std::string castling;
        std::string enPassantTarget;
        int halfMoveClock;
        int fullMoveNumber;
    }*boardState;
    void initBoard();
    void setBoardFromCurrentState();
    void MakeMove(Move* move);

};

#endif // BOARDWIDGET_H
