#include "pawn.h"

Pawn::Pawn(Square* parent, Square* (&board)[boardSize][boardSize], char color):
    ChessPiece(parent, board, color)
{
    generateLegalMoves();
}

