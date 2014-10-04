//// Oil.cpp (Uses DFS to find oil deposits
//#include <iostream>
//#include <fstream>
//#include <vector>
//using namespace std;
//
//// const int MAXROWS = 100;
//// const int MAXCOLS = 100;
//
//#define OIL	   '@'
//#define NO_OIL '*'
//#define Marker 'X'
//#define Marked(ch) (ch == Marker)
//
//typedef vector<vector<char>> OilPocketType;
//
//void Mark(OilPocketType &pocket, int row, int col) { pocket[row][col] = Marker; }
//
//void FillDeposit(OilPocketType &pocket, int row, int col)
//{
//	Mark(pocket, row, col);
//
//	// for all nodes adjacent to node: [row][col]
//	for (int i = -1; i <= 1; i++)
//	{
//		for (int j = -1; j <= 1; j++)
//		{
//			int NewRow = row + i;
//			int NewCol = col + j;
//			if ((pocket[NewRow][NewCol] == OIL) && !Marked(pocket[NewRow][NewCol]))
//			{
//				FillDeposit(pocket, NewRow, NewCol);
//			}
//		}
//	}
//}
//
//int FindDeposits(OilPocketType &pocket, int NumRows, int NumCols)
//{
//	int NumDeposits = 0;
//
//	for (int row = 1; row <= NumRows; row++)
//	{
//		for (int col = 1; col <= NumCols; col++)
//		{
//			if (pocket[row][col] == OIL && !Marked(pocket[row][col]))
//			{
//				NumDeposits++;
//				FillDeposit(pocket, row, col);
//			}
//		}
//	}
//	return NumDeposits;
//}
//
//void main()
//{
//	ifstream fin("oil.in");
//	if (fin)
//	{
//		ofstream fout("oil.out");
//		int NumRows, NumCols;
//		int NumDeposits;
//		int GridNum = 0;
//		OilPocketType pocket; // ..or.. char pocket[MAXROWS][MAXCOLS];
//
//		fin >> NumRows >> NumCols;
//		while (NumRows > 0 && NumCols > 0)
//		{
//			GridNum++;
//			// Read in test case for new grid
//			for (int i = 0; i <= NumRows + 1; i++)
//			{
//				vector<char> RowVector;
//				for (int j = 0; j <= NumCols + 1; j++)
//				{
//					if (i == 0 || i > NumRows || j == 0 || j > NumCols)
//					{
//						RowVector.push_back(NO_OIL);
//					}
//					else
//					{
//						char ch;
//						fin >> ch;
//						RowVector.push_back(ch);
//					}
//				}
//				pocket.push_back(RowVector);
//				RowVector.clear();
//			}
//
//			NumDeposits = FindDeposits(pocket, NumRows, NumCols);
//			if (NumDeposits == 0)
//			{
//				fout << "Grid #" << GridNum << " doesn't contain an oil deposit" << endl;
//				cout << "Grid #" << GridNum << " doesn't contain an oil deposit" << endl;
//			}
//			else
//			{
//				fout << "Grid #" << GridNum << " contains " << NumDeposits << " oil deposits";
//				cout << "Grid #" << GridNum << " contains " << NumDeposits << " oil deposits";
//				if (NumDeposits > 1)
//				{
//					fout << "s";
//					cout << "s";
//				}
//				fout << "." << endl;
//				cout << "." << endl;
//			}
//
//			pocket.clear();
//			fin >> NumRows >> NumCols;
//		}
//		fout.close();
//		fin.close();
//	}
//}