#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "square.h"
#include "move.h"
#include <vector>
#include <QTextStream>

class ChessPiece
{
protected:
    static const int boardSize = 8;
    Square* parent;
    std::vector<Move> moves;
    Square* (&board) [boardSize][boardSize];
    void generateLegalMoves();
    char color;
    int index;

public:
    ChessPiece(Square* parent, Square* (&board)[boardSize][boardSize], char color);
    std::vector<Move> getLegalMoves() const;
};

#endif // CHESSPIECE_H
