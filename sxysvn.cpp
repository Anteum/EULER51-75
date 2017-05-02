#include "connect3.h"

class triSet
{
public:
	triSet(int s)
	{
		size = s;
		for (int i = 0; i < size; i++)
			triVec.push_back(vector<short>(i + 1, 0));
	}
	vector<vector<short>> triVec;

private:
	int size;
	
};


int sxysvn()//by always moving to an adjacent number below, find the path from the top to the bottom
{//of the triangle in "triangle.txt" with the maximum sum
	
	vector<short> path;
	const int max = 100;
	triSet t(max);
	ifstream ints("triangle.txt");
	for (int i = 0; i < max; i++)//fill triarray
		for (int j = 0; j <= i; j++)
			ints >> t.triVec[i][j];
	ints.close();
	for (int row = max - 2; row >= 0; row--)//based on description by Project Euler user: mather, given as a sol for Problem #18
	{//working from 2nd row from bottom and going up, for each element, add to it the greater adjacent number below
		for (int col = 0; col <= row; col++)
		{
			if (t.triVec[row + 1][col] > t.triVec[row + 1][col + 1])
				t.triVec[row][col] += t.triVec[row + 1][col];
			else
				t.triVec[row][col] += t.triVec[row + 1][col + 1];
		}
	}
	cout << t.triVec[0][0] << endl;//max sum is located in top element
	
	return 0;
}