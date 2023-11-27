#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"

class Pawn : public ChessPiece
{
public:
    Pawn(Square* parent, Square* (&board)[boardSize][boardSize], char color);

};

#endif // PAWN_H
