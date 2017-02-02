#include "Maze.h"								// Sara Savitz
#include <queue>								// U37713110
#include <iostream>								// COP 4530
#include <cstdlib>
#include <cassert>

using namespace std;


void Maze::print_dfsExitPath()
{
   stack<Position> path;
   Position current, nbr;
   // FILL IN MISSING CODE

   setState(start, VISITED);
   current = start;
   path.push(current);

   
  while(!(current == exitpos))	// Loop will break when the exit is found
  {

   while(getState(current.Neighbor(DOWN)) == OPEN)
   {

   		nbr = current.Neighbor(DOWN);
   		setState(nbr, VISITED);
   		path.push(nbr);
   		current = nbr;

   		if(nbr == exitpos)
   		{
   			cout << "Remy, here is a sequence of positions to escape the maze:\n";
   			printBottomToTop(path);	
   		}
   			
    	
    }	

    while(getState(current.Neighbor(LEFT)) == OPEN && getState(current.Neighbor(DOWN)) != OPEN)
    {
    	nbr = current.Neighbor(LEFT);
    	setState(nbr, VISITED);
    	path.push(nbr);
    	current = nbr;

    	if (nbr == exitpos)
    	{
    		cout << "Remy, here is a sequence of positions to escape the maze:\n";
    		printBottomToTop(path);
    	}
   	
    	
    	  
   }

   while (getState(current.Neighbor(UP)) == OPEN 
   	&& getState(current.Neighbor(LEFT)) != OPEN 
   	&& getState(current.Neighbor(DOWN)) != OPEN)
   {
   		nbr = current.Neighbor(UP);
   		setState(nbr, VISITED);
   		path.push(nbr);
   		current = nbr;

   		if(nbr == exitpos)
   		{
   			cout << "Remy, here is a sequence of positions to escape the maze:\n";
   			printBottomToTop(path);
   		}

   }

   while(getState(current.Neighbor(RIGHT)) == OPEN 
   	&& getState(current.Neighbor(UP)) != OPEN
   	&& getState(current.Neighbor(LEFT)) != OPEN
   	&& getState(current.Neighbor(DOWN)) != OPEN)
   {
   		nbr = current.Neighbor(RIGHT);
   		path.push(nbr);
   		setState(nbr, VISITED);
   		current = nbr;

   		if(nbr == exitpos)
   		{
   			cout << "Remy, here is a sequence of positions to escape the maze:\n";
   			printBottomToTop(path);
   		}
   		
   }

   // If no neighbor is marked as OPEN, pop an item off the stack
   // If stack is not empty, assign current to top of stack
   if(!(current == exitpos) && !(path.empty()) &&
   	getState(current.Neighbor(DOWN)) != OPEN &&
   	getState(current.Neighbor(LEFT)) != OPEN &&
   	getState(current.Neighbor(UP)) != OPEN &&
   	getState(current.Neighbor(RIGHT)) != OPEN)
   {

   		path.pop();

   		if (!(path.empty()))
   			current = path.top();
   		
   }

	if(path.empty())	// If stack is empty, no path was found
	{
		cout << "Oh no, poor Remy! There is no way to escape from the Maze\n\n" << endl;
		break;
	}
	
	}	
}
   


void Maze::printShortestPath()
{
   queue<Position> Q;
   Position current, nbr;
   // Allocate the two dimensional predecessor array
   // The predecessor of Position P is given by
   // predecessor[P.row][P.col]
   Position** predecessor = new Position *[size];
   for(int i = 0; i < size; ++i) {
      predecessor[i] = new Position[size];
      for(int j = 0; j < size; ++j)
	 predecessor[i][j] = NULLPOS;
   }
   // FILL IN MISSING CODE

   direction d;
   setState(start, VISITED);
   Q.push(start);
   predecessor[current.getRow()][current.getCol()] = current;

   while(!(Q.empty()))
   {
   	current = Q.front();
   	Q.pop();
   	d = DOWN;

   	while(d != NONE)
   	{
   		if(getState(current.Neighbor(d)) == OPEN)
   		{
   			nbr = current.Neighbor(d);
   			setState(nbr, VISITED);
   			Q.push(nbr);
   			predecessor[nbr.getRow()][nbr.getCol()] = current; 
   		}

   		if(nbr == exitpos)
   		{
   			cout << "Remy, here is a shortest sequence of positions to escape the maze:\n";
   			printPredecessorPath(predecessor, nbr);
   			return;
   		}
   		 
   		d = next_direction(d); 

   	}

  }
  cout << "Oh no, poor Remy! There is now way to escape from the maze.\n\n";
  return;
}

