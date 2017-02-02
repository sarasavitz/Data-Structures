main:   Position.o Maze.o suppliedMazeFuncs.o RescueRemy.o
	g++ Position.o Maze.o RescueRemy.o suppliedMazeFuncs.o -o main

RescueRemy.o:  RescueRemy.cpp Position.h Maze.h
	g++ -c RescueRemy.cpp

Position.o:  Position.cpp Position.h
	g++ -c Position.cpp 

Maze.o:   Maze.h Maze.cpp
	g++ -c Maze.cpp

suppliedMazeFuncs.o: suppliedMazeFuncs.cpp Maze.h
	g++ -c suppliedMazeFuncs.cpp

