// by JJeong

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <fstream>

#include "deque.hpp";
#include "image.h";

struct point {
	size_t row;
	size_t column;
};

using namespace std;

int main(int argc, char *argv[])
{
	//Checking if command input is correct
	if (argc != 3)
	{
		cerr << "Error, invalid number of arguments." << endl;
		return EXIT_FAILURE;
	}

	//Read maze
	Image<Pixel> maze = readFromFile(argv[1]);

	//Finding starting point
	size_t maze_w = maze.width();
	size_t maze_h = maze.height();

	point start;
	int countRed = 0;
	int countColors = 0;
	for (int i = 0; i < maze_w; i++)
	{
		for (int j = 0; j < maze_h; j++)
		{
			if (maze(i, j) == RED)
			{
				start.row = i;
				start.column = j;
				countRed++;
			}
			if (maze(i, j) != RED && maze(i, j) != BLACK && maze(i, j) != WHITE)
			{
				countColors++;
			}
		}
	}
	if (countRed != 1)
	{
		cerr << "Error, maze includes more than one starting point." << endl;
		return EXIT_FAILURE;
	}
	if (countColors != 0)
	{
		cerr << "Error, maze includes invalid colors." << endl;
		return EXIT_FAILURE;
	}

	//Finding solution
	Deque<point> Frontier;
	Deque<point> possible;
	Image<Pixel> Explored(maze_w, maze_h);
	point solution;
	point current;
	bool foundOrNot = false; //indicates whether solution was found
	bool quitSearch = false; //indicates when to quit search

	Frontier.pushBack(start);
	Explored(start.row, start.column) = BLUE; //mark start point in Explored maze as reference

	while (quitSearch == false)
	{
		if (Frontier.isEmpty())
		{
			quitSearch = true;
			continue;
		}

		//left
		if (maze(Frontier.front().row - 1, Frontier.front().column) == WHITE)
		{
			current.row = Frontier.front().row - 1;
			current.column = Frontier.front().column;
			possible.pushFront(current);
		}

		//right
		if (maze(Frontier.front().row + 1, Frontier.front().column) == WHITE)
		{
			current.row = Frontier.front().row + 1;
			current.column = Frontier.front().column;
			possible.pushFront(current);
		}

		//up
		if (maze(Frontier.front().row, Frontier.front().column + 1) == WHITE)
		{
			current.row = Frontier.front().row;
			current.column = Frontier.front().column + 1;
			possible.pushFront(current);
		}

		//down
		if (maze(Frontier.front().row, Frontier.front().column - 1) == WHITE)
		{
			current.row = Frontier.front().row;
			current.column = Frontier.front().column - 1;
			possible.pushFront(current);
		}

		//Pop frontier
		Frontier.popFront();

		//If point is not solution, store point into Explored(copy of input maze)
		//Color the explored points into blue and compare with possible points to avoid searching for duplicates
		int countPossible = possible.getLength();
		for (int i = 0; i < countPossible; i++)
		{
			current = possible.back();
			if (Explored(current.row, current.column) != BLUE)
				if (current.row == 0 || current.column == 0 || current.row == maze_w - 1 || current.column == maze_h - 1)
				{
					solution.row = current.row;
					solution.column = current.column;
					foundOrNot = true;
					quitSearch = true;
					continue;
				}
				else
				{
					Frontier.pushBack(current);
					Explored(current.row, current.column) = BLUE;
				}
			possible.popBack();
		}
	}

	//Writing output maze
	if (foundOrNot == false)
	{
		writeToFile(maze, argv[2]);
		cout << "No Solution Found" << endl;
		return EXIT_SUCCESS;
	}
	else
	{
		maze(solution.row, solution.column) = GREEN;
		writeToFile(maze, argv[2]);
		cout << "Solution Found" << endl;
		return EXIT_SUCCESS;
	}
}
