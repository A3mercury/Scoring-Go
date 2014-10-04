//// Scoring Go
//// Austin Andrews
//// Visual Studio 2013
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <stack>
//using namespace std;
//
//const string INPUT = "go.in";
//const string OUTPUT = "go.out";
//const int BOARD_SIZE = 21;
//
//struct Coordinate
//{
//	int x, y;
//};
//
//void displayBoard(int boardArray[][BOARD_SIZE], int size)
//{
//	for (int i = 0; i <= size + 1; i++)
//	{
//		for (int j = 0; j <= size + 1; j++)
//		{
//			cout << boardArray[i][j];
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//void flushArray(int boardArray[][BOARD_SIZE])
//{
//	for (int i = 0; i < BOARD_SIZE; i++)
//		for (int j = 0; j < BOARD_SIZE; j++)
//			boardArray[i][j] = 1;
//}
//
//void generateNewBoard(int boardArray[][BOARD_SIZE], int size)
//{
//	for (int i = 0; i <= size + 1; i++)
//	{
//		for (int j = 0; j <= size + 1; j++)
//		{
//			if (i == 0 || i == size+1)
//				boardArray[i][j] = 0;
//			else if (j == 0 || j == size+1)
//				boardArray[i][j] = 0;
//			else
//				boardArray[i][j] = 1;
//		}
//	}
//}
//
//void main()
//{
//	ifstream fin(INPUT);
//	if (fin)
//	{
//		ofstream fout(OUTPUT);
//		int boardSize, numBlack, numWhite;
//		vector<Coordinate> BlackCoordinates;
//		vector<Coordinate> WhiteCoordinates;
//		stack<Coordinate> Stack;
//
//		// largest boardsize + 1 on each side
//		// also starts at 1,1 instead of 0,0
//		int boardArray[BOARD_SIZE][BOARD_SIZE];
//
//		fin >> boardSize >> numBlack >> numWhite;
//		while (boardSize != 0)
//		{
//			flushArray(boardArray);
//			generateNewBoard(boardArray, boardSize);
//
//			// get black positions
//			Coordinate Black;
//			for (int i = 0; i < numBlack; i++)
//			{
//				fin >> Black.x >> Black.y;
//				boardArray[Black.x][Black.y] = 2;
//			}
//
//			// get white positions
//			Coordinate White;
//			for (int i = 0; i < numWhite; i++)
//			{
//				fin >> White.x >> White.y;
//				boardArray[White.x][White.y] = 3;
//			}
//
//			displayBoard(boardArray, boardSize);
//
//			// Construct GameBoard
//			for (int i = 0; i < boardSize + 1; i++)
//				for (int j = 0; j < boardSize + 1; j++)
//					if (boardArray[i][j] != 2 && boardArray[i][j] != 3)
//						boardArray[i][j] = 1;
//
//			// Score Game
//			for (int i = 1; i <= boardSize; i++)
//			{
//				for (int j = 1; j <= boardSize; j++)
//				{
//					if (boardArray[i][j] == 1)
//					{
//
//					}
//				}
//			}
//
//			fin >> boardSize >> numBlack >> numWhite;
//		}
//
//		fout.close();
//		fin.close();
//	}
//	else
//	{
//		cout << "Input file not found." << endl;
//	}
//}