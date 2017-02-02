#ifndef __MAZE
#define __MAZE

#include <iostream>
#include <cassert>
#include "Position.h"
#include <stack>
#include <queue>
// Note the use of the STL queue ADT
// Be aware that it uses push instead of enqueue
// and pop instead of dequeue; front is the same as our Queue classes

const Position NULLPOS(-1,-1);

using namespace std;

typedef enum{OPEN,WALL,VISITED} state;

// Allocates a dynamic two-dimensional arrar of states
// having size rows and size columns; returns the pointer
// used to create the array
state **getMazeArray(int size);

class Maze
{
  public:
   static const int MAZEMAX = 12; // default maze size

   //      CONSTRUCTORS      //
   
   //start set to upper left corner, exit to lower right corner, size to MAZEMAX
   Maze();

   //start set to upper left corner, exit to lower right corner, size to n
   Maze(int n);

   //start set to s, exit to e, size to MAZEMAX
   Maze(Position s, Position e);

   //start set to s, exit to e, size to n
   Maze(int n, Position s, Position e);

   // Copy constructor
   Maze(const Maze & other);
   
   Maze & operator=(const Maze & origMaze);
   
   ~Maze();

   void initialize(); 
   // input the start and exit positions; then input, for each row, 
   // the column indices of the OPEN squares in that row

   void display(ostream &out) const;
   // Print the contents of the maze, one row per line
   // For each Position, print '*' if the Position's state is WALL
   // Otherwise, print a space.

   state getState(const Position &P) const;
   
   void setState(const Position &P, state s);
   // precondition: P corresponds to a non-hedge position within the maze

   void print_dfsExitPath();
   // Applies dfs method for finding a path to the exit
   // If such a path is found, it prints the message
   // "Remy, here is a sequence of positions to escape the maze:\n"
   // and then prints the path from the start to the exit position  

   // If no path is found, it prints
   // "Oh no, Poor Remy! There is now way to escape from the maze.\n\n"
   //
   // Uses: printBottomToTop(stack<Position> S)

   void printShortestPath();
   // Applies bfs method for finding a shortest path to the exit
   // If such a path is found, it prints the path from
   // the start to the exit position.  If not, prints
   // "No way out"
   // Applies bfs method for finding a shortest path to the exit
   // If such a path is found, it prints the message
   // "Remy, here is a sequence of positions to escape the maze:\n"
   // and then prints the path from the start to the exit position  

   // If no path is found, it prints
   // "Oh no, Poor Remy! There is now way to escape from the maze.\n\n"
   //
   // Uses printPredecessorPath(queue<Position> Q)


  private:
   int size;
   Position start;
   Position exitpos;
   state **M; // two-dimensional array of state values
};

void printBottomToTop(stack<Position> S);

void printPredecessorPath(Position **pred, Position target);
// Print the path from the start to the target as specified
// by the predecessor array

#endif
