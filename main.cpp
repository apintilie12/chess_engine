#include <QCoreApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QGraphicsView>
#include <QRect>
#include <QDesktopWidget>
#include <QLabel>
#include <iostream>
#include <QGridLayout>
#include "square.h"
#include "boardwidget.h"
#include "move.h"

void setCentralWidget(QMainWindow* parent)
{
    QWidget* centralWidget = new QWidget();
    QVBoxLayout* l = new QVBoxLayout();
    BoardWidget* board = new BoardWidget(parent);
    l->addWidget(board);
    board->readFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    board->test();
    centralWidget->setLayout(l);
    parent->setCentralWidget(centralWidget);

    int width = 800, height = 600;
    parent->resize(width, height);



}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow* w = new QMainWindow();

    setCentralWidget(w);

    w->show();


    return a.exec();
}
