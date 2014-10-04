// Scoring Go
// Austin Andrews
// Visual Studio 2013
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

const string INPUT = "go.in";
const string OUTPUT = "go.out";

#define BOARDER '+'
#define CELLS   '.'
#define BLACK   'B'
#define WHITE   'W'
#define MARKER  '/'
#define MARKED(ch) (ch == MARKER)

typedef vector<vector<char>> BoardType;

void Mark(BoardType& GameBoard, int row, int col) { GameBoard[row][col] = MARKER; }

struct Coordinate
{
	int x, y;
};

void countEmptyCells(BoardType& GameBoard, int& emptyCells, bool& touchBlack, bool& touchWhite, int row, int col)
{
	Mark(GameBoard, row, col);

	// for all cells adjacent to the current cell: [row][col]
	// adjacent cells are |row - NewRow| + |col - NewCol|
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int NewRow = row + i;
			int NewCol = col + j;
			if (abs(row - NewRow) + abs(col - NewCol) == 1)
			{
				if ((GameBoard[NewRow][NewCol] == CELLS) && !MARKED(GameBoard[NewRow][NewCol]))
				{
					emptyCells++;
					countEmptyCells(GameBoard, emptyCells, touchBlack, touchWhite, NewRow, NewCol);
				}
				else if (GameBoard[NewRow][NewCol] == BLACK)
				{
					touchBlack = true;
				}
				else if (GameBoard[NewRow][NewCol] == WHITE)
				{
					touchWhite = true;
				}
			}
		}
	}
}

void ScoreGame(BoardType GameBoard, int boardSize, int& blackCount, int& whiteCount)
{
	bool touchBlack = false;
	bool touchWhite = false;
	int emptyCells = 0;
	for (int row = 1; row <= boardSize; row++)
	{
		for (int col = 1; col <= boardSize; col++)
		{
			if (GameBoard[row][col] == CELLS && !MARKED(GameBoard[row][col]))
			{
				emptyCells++;
				countEmptyCells(GameBoard, emptyCells, touchBlack, touchWhite, row, col);
				if (touchBlack && !touchWhite)
					blackCount += emptyCells;
				else if (!touchBlack && touchWhite)
					whiteCount += emptyCells;

				touchBlack = false;
				touchWhite = false;
				emptyCells = 0;
			}
		}
	}
}

void main()
{
	ifstream fin(INPUT);
	if (fin)
	{
		ofstream fout(OUTPUT);
		int boardSize, numBlack, numWhite;
		BoardType GameBoard;
		vector<Coordinate> BlackCoordinates;
		vector<Coordinate> WhiteCoordinates;

		fin >> boardSize >> numBlack >> numWhite;
		while (boardSize != 0)
		{
			// get black positions
			Coordinate Black;
			for (int i = 0; i < numBlack; i++)
			{
				fin >> Black.x >> Black.y;
				BlackCoordinates.push_back(Black);
			}
			if (BlackCoordinates.size() == 0)
			{
				Black.x = -1; Black.y = -1;
				BlackCoordinates.push_back(Black);
			}

			// get white positions
			Coordinate White;
			for (int i = 0; i < numWhite; i++)
			{
				fin >> White.x >> White.y;
				WhiteCoordinates.push_back(White);
			}
			if (WhiteCoordinates.size() == 0)
			{
				White.x = -1; White.y = -1;
				WhiteCoordinates.push_back(White);
			}

			// Construct GameBoard
			for (int i = 0; i <= boardSize + 1; i++)
			{
				vector<char> FillCells;
				for (int j = 0; j <= boardSize + 1; j++)
				{
					if (i == 0 || i == boardSize + 1 || j == 0 || j == boardSize + 1)
						FillCells.push_back(BOARDER);
					else
						FillCells.push_back(CELLS);
				}
				GameBoard.push_back(FillCells);
				FillCells.clear();
			}

			// Assign Black Coordinates to GameBoard
			for (int blackPos = 0; blackPos < BlackCoordinates.size(); blackPos++)
				if (BlackCoordinates.at(blackPos).x != -1 && BlackCoordinates.at(blackPos).y != -1)
					GameBoard[BlackCoordinates.at(blackPos).x][BlackCoordinates.at(blackPos).y] = BLACK;
			
			// Assign White Coordinates to GameBoard
			for (int whitePos = 0; whitePos < WhiteCoordinates.size(); whitePos++)
				if (WhiteCoordinates.at(whitePos).x != -1 && WhiteCoordinates.at(whitePos).y != -1)
					GameBoard[WhiteCoordinates.at(whitePos).x][WhiteCoordinates.at(whitePos).y] = WHITE;

			// Score Game
			int blackCount = 0, whiteCount = 0;
			ScoreGame(GameBoard, boardSize, blackCount, whiteCount);

			if (blackCount == whiteCount)
				fout << "draw" << endl;
			else if (blackCount > whiteCount)
				fout << "black wins by " << blackCount - whiteCount << endl;
			else if (blackCount < whiteCount)
				fout << "white wins by " << whiteCount - blackCount << endl;
		
			GameBoard.clear();
			BlackCoordinates.clear();
			WhiteCoordinates.clear();
			fin >> boardSize >> numBlack >> numWhite;
		}
		fout.close();
		fin.close();
	}
	else
	{
		cout << "Input file not found." << endl;
	}
}