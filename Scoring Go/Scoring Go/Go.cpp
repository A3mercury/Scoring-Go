// Scoring Go
// Austin Andrews
// Visual Studio 2013
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

const string INPUT = "go.in";
const string OUTPUT = "go.out";

#define BOARDER '0'
#define CELLS   ' '
#define BLACK   'b'
#define WHITE   'w'

typedef vector<vector<char>> BoardType;
struct Coordinate
{
	int x, y;
};

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

			// get white positions
			Coordinate White;
			for (int i = 0; i < numWhite; i++)
			{
				fin >> White.x >> White.y;
				WhiteCoordinates.push_back(White);
			}

			for (int i = 0; i <= boardSize+1; i++)
			{
				vector<char> RowVector;
				for (int j = 0; j <= boardSize+1; j++)
				{
					if (i == 0 || i > boardSize || j == 0 || j > boardSize)
					{
						RowVector.push_back(CELLS);
					}
					else
					{

						//RowVector.push_back();
					}
				}
			}

			// Construct GameBoard
			for (int i = 0; i < boardSize + 1; i++)
				for (int j = 0; j < boardSize + 1; j++)
					if (GameBoard[i][j] != BLACK && GameBoard[i][j] != WHITE)
						GameBoard[i][j] = CELLS;

			for (int i = 0; i < boardSize + 1; i++)
			{
				for (int j = 0; j < boardSize + 1; j++)
					cout << GameBoard[i][j];
				cout << endl;
			}
			cout << endl;


			// Score Game
		
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