#include <iostream>
#include "Position.h"
#include "Maze.h"

int main()
{
  int maze_size, dimension;
  cout << "Welcome to the Rat in the Maze program, where we will find a\n"
       << "path from the start cell to the end cell of a maze so that Remy\n"
       << "may escape.  You will first enter the data specifying the maze.\n"
       << "After that, if escape is possible, we show an escape path using\n"
       << " DFS and then a shortest possible path\n" << endl;
  cout << "Enter the size (number of rows and columns of the square maze): ";

  cin >> maze_size;
  cout << "\n" << endl;
  dimension = maze_size+2;

  Maze RatHaus1(dimension);

  RatHaus1.initialize();

  Maze RatHaus2(RatHaus1);
  cout << "\n\nYour maze:\n";
  RatHaus1.display(cout);

  RatHaus1.print_dfsExitPath();
  cout << "\n\n";
  RatHaus2.printShortestPath();
  cout << "\n\n";

  return 0;
}
