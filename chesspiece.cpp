#include "chesspiece.h"

ChessPiece::ChessPiece(Square* parent, Square* (&board)[boardSize][boardSize], char color):
    parent(parent), board(board), color(color)
{

}

void ChessPiece::generateLegalMoves(){}
