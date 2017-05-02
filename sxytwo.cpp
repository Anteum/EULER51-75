#include "connect3.h"

int sxytwo()//find smallest cube number for which 5 permutations of it are cube
{//
	vector<vector<vector<short>>> cubePermTable;//view as a table of cubeVs
	vector<short> cubeV;
	long long cube;
	bool used = false;
	cube = 345*345*345;
	cubeV = itov(cube);
	cubePermTable.push_back(vector<vector<short>>(1, cubeV));
	for (long long x = 346; x <= 110000; x++)//345^3 is given as smallest cube with 3 cube perms
	{//110000^3 is 5th cube perm of 100001^3, so don't need to go past 110000
		cout << x << endl;
		cube = x*x*x;//x is long long so cube calculation is long long
		cubeV = itov(cube);
		used = false;
		for (int i = 0; i < cubePermTable.size(); i++)//for each new cube, check if perm of previous cubes
		{//only want to test perm of cubes of same length
			if (cubeV.size() > cubePermTable[i][0].size())//havent made it to cubes of right length
				continue;
			if (cubeV.size() < cubePermTable[i][0].size())//gone past cubes of right length
				break;
			if (is_permutation(cubeV.begin(), cubeV.end(), cubePermTable[i][0].begin()))
			{
				cubePermTable[i].push_back(cubeV);//if is a perm, add to that cube's row 
				used = true;
				if (cubePermTable[i].size() == 5)//test for winners
				{
					vPrint(cubePermTable[i][0]);
					cin.get();
				}
				break;
			}
		}
		if (!used)
		{
			cubePermTable.push_back(vector<vector<short>>(1, cubeV));//if not any cube's perm, add to new row
		}
	}

	return 0;
}