#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent)
{
    white = QColor(207, 191, 151);
    black = QColor(122, 93, 54);
    layout = new QGridLayout(this);
    layout -> setHorizontalSpacing(0);
    layout -> setVerticalSpacing(0);
    initBoard();
    boardState = new state;
}

void BoardWidget::readFen(std::string fen)
{
    int i = 0, b = 0;
    //Reading piece placement
    while(fen[i] != ' ')
    {
        ++i;
    }
    boardState->piecePlacement = fen.substr(b, i - b);
    ++i;
    //Set active color
    boardState->activeColor = fen[i];
    i += 2;
    b = i;
    //Reading castling rights
    while(fen[i] != ' ')
    {
        ++i;
    }
    boardState -> castling = fen.substr(b, i - b + 1);
    //Reading en passant target
    b = i + 1;
    i++;
    while(fen[i] != ' ')
    {
        ++i;
    }
    boardState -> enPassantTarget = fen.substr(b, i - b + 1);
    //Read half move clock
    ++i;
    boardState -> halfMoveClock = fen[i] - '0';
    i += 2;
    boardState -> fullMoveNumber = fen[i] - '0';
    setBoardFromCurrentState();
}

void BoardWidget::initBoard()
{
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            if((i + j) % 2 == 0)
            {
                sq[i][j] = new Square(nullptr,white);
                //sq[i][j] ->setColor(this -> white);
            }
            else
            {
                sq[i][j] = new Square(nullptr,black);
               //sq[i][j] ->setColor(this -> black);
            }
            layout->addWidget(sq[i][j], i, j);

        }
    }
}

void BoardWidget::setBoardFromCurrentState()
{
    unsigned int i, j;
    i = 0;
    j = 0;
    char c;
    while(j < boardState->piecePlacement.length())
    {
        c = boardState->piecePlacement[j];
        if(c == '/')
        {
            ++j;
        }
        else if(isalpha(c))
        {
            sq[i / boardSize][ i % boardSize]->setPiece(c);
            sq[i / boardSize][i % boardSize]->update();
            ++i;
            ++j;
        }
        else if(isdigit(c))
        {
            i += c - '0';
            ++j;
        }
    }

}

void BoardWidget::test()
{
    ChessPiece test = ChessPiece(sq[0][0],sq,'w');
    //test.test();
}
