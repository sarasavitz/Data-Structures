//-------------Position.cpp---------------//

#include "Position.h"
#include <iostream>
#include <cassert>

using namespace std;

direction next_direction(direction d)
{
   switch(d)
   {
      case DOWN: return LEFT;
      case LEFT: return UP;
      case UP: return RIGHT;
      default: return NONE;
   }
}

Position Position::Neighbor(direction d) const
{
   switch(d) {
      case DOWN:
	 return Position(row+1,col);
      case LEFT:
	 return Position(row,col-1);
      case UP:
	 return Position(row-1,col);
      case RIGHT:
	 return Position(row,col+1);
   }
}

bool Position::operator==(const Position &other) const
{
   return row == other.row && col == other.col;
}


void Position::display(ostream & out) const
{
   out << '('<< row << ',' << col << ')';
}

void Position::input(istream & in)
{
   cout << "row index: ";
   in >> row;
   cout << "column index: ";
   in >> col;
}

ostream & operator<<(ostream &out, const Position &P)
{
   P.display(out);
   return out;
}

istream & operator>>(istream &in, Position &P)
{
   P.input(in);
   return in;
}
