#ifndef MOVE_H
#define MOVE_H

#include "square.h"

class Move
{
public:
    Move(Square *origin, Square *destination, bool isCapture, char piece);
    void setOrigin(Square *origin);
    void setDestination(Square *destination);
    void setCaptureStatus(bool isCapture);
    void setPiece(char piece);
    Square* getOrigin() const;
    Square* getDestination() const;
    bool getCaptureStatus()const;
    char getPiece() const;

    static int getNumericIndex(std::string algebraic);
    static std::string getAlgebraicIndex(int numeric);

private:
    Square *origin;
    Square *destination;
    bool isCapture;
    char piece;

};

#endif // MOVE_H
