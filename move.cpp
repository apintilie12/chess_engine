#include "move.h"

Move::Move(Square *origin, Square *destination, bool isCapture, char piece):
    origin(origin), destination(destination), isCapture(isCapture), piece(piece)
{

}

void Move::setOrigin(Square *origin)
{
    this -> origin = origin;
}

void Move::setDestination(Square *destination)
{
    this -> destination = destination;
}

void Move::setCaptureStatus(bool isCapture)
{
    this -> isCapture = isCapture;
}

void Move::setPiece(char piece)
{
    this -> piece = piece;
}

Square* Move::getOrigin() const
{
    return this -> origin;
}

Square* Move::getDestination() const
{
    return this -> destination;
}

bool Move::getCaptureStatus() const
{
    return isCapture;
}

char Move::getPiece() const
{
    return this -> piece;
}

int Move::getNumericIndex(std::string algebraic)
{
    std::vector<int> translator = {7,6,5,4,3,2,1,0};
    int index;
    int column, row;
    column = algebraic[0] - 'a';
    row = translator[algebraic[1] - '1'];
    index = row * 8 + column;
    return index;
}

std::string Move::getAlgebraicIndex(int numeric)
{
    std::vector<char> rows = {'8','7','6','5','4','3','2','1'};
    std::vector<char> columns = {'a','b','c','d','e','f','g','h'};
    std::string algebraic = {""};
    char column = columns[numeric % 8];
    char row = rows[numeric / 8];
    algebraic.push_back(column);
    algebraic.push_back(row);
    return algebraic;
}
