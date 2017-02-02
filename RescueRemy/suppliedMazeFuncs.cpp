#include "Maze.h"
#include <cstdlib>

state **getMazeArray(int size) {
  state **A;
  try {
    A = new state *[size];
  }
  catch(bad_alloc) {
    cerr << "Unable to allocate array of state pointers";
    exit(1);
  }
  for(int i = 0; i < size; i++) {
    try {
      A[i] = new state[size];
    }
    catch (bad_alloc) {
      cerr << "Unable to allocate row of state values";
      exit(1);
    }
  }
  return A;
}

Maze::Maze()
{ 
  size= MAZEMAX;
  start = Position(1,1);
  exitpos = Position(MAZEMAX-2,MAZEMAX-2);
  M = getMazeArray(size);
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      M[i][j] = WALL;
}   

Maze::Maze(int max)
{
  size = max;
  start = Position(1,1); // Upper left corner position
  exitpos = Position(size-2,size-2); // lower right corner position
  M = getMazeArray(size);  
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      M[i][j] = WALL;
}

Maze::Maze(const Maze & other): 
  size(other.size), start(other.start), exitpos(other.exitpos)
{
  M = getMazeArray(size);
  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++)
      M[i][j] = other.M[i][j];
  }
}

// Assignment operator overload here
Maze & Maze::operator=(const Maze & origMaze) {
  if (size != origMaze.size) {
    state **hold = M;
    size = origMaze.size;
    M = getMazeArray(size);
    delete []hold;
  }

  for(int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      M[i][j] = origMaze.M[i][j];
}


Maze::~Maze()
{
  for(int i = 0; i < size; ++i) {
    delete [] M[i];
  }
  delete [] M;
}

void Maze::initialize() // Assumes size already set
{
  int i, j;
  cout << "\nEnter the start position\n";
  cin >> start;
  cout << "\nEnter the exit position\n";
  cin >> exitpos;

  cout << "\n\nFor each row, enter the column indexes of the open positions,\n";
  cout << "separated by spaces and terminated by an entry of 0\n";
  for (i = 1; i < size-1; i++) {
    cout << "\nrow " << i << ": ";
    cin >> j;
    while (j > 0){
      M[i][j] = OPEN;
      cin >> j;
    };
  }
  if (getState(start) != OPEN) {
    M[start.getRow()][start.getCol()] = OPEN;
  }
}

state  Maze::getState(const Position &P) const
{
  return M[P.getRow()][P.getCol()];
}

void Maze::display(ostream &out) const
{
  out << '\n';
  for (int i=0; i < size;i++) {
    for (int j=0; j < size; j++)
      if (Position(i,j) == start && start == exitpos)
	cout << 'b';
      else if (Position(i,j) == start)
	cout << 's';
      else if (Position(i,j) == exitpos)
	cout << 'e';
      else if (M[i][j] == WALL)
	out << '*';
      else
	out << '|';
    out << '\n';
  }
  out << '\n';
}

void Maze::setState(const Position &P, state s)
{
  int i = P.getRow();
  int j = P.getCol();
  assert(1 <= i && i <= size && 1 <= j && j <= size);
  M[i][j] = s;
}

void printBottomToTop(stack<Position> S)
{
  if (S.empty())
    return;
  Position target = S.top();
  S.pop();
  printBottomToTop(S);
  cout << target << " ";
}

void printPredecessorPath(Position **pred, Position target)
{
  if (target == NULLPOS)
    return;
  printPredecessorPath(pred,pred[target.getRow()][target.getCol()]);
  cout << target << " ";
}
