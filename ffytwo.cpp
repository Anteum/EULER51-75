#include "connect3.h"

int ffytwo()//smallest n where 2n, 3n,...6n are permutations of each other
{
	vector<short> twoxvec, mxvec;
	for (int i = 2; i <= 10; i++)//10 is arbitrary "large" number
	{
		int start = pow(10, i) / 2;//make n such that 2n thru 6n have same number of digits
		long long end = 5 * pow(10, i) / 3;
		//cout << start<<' ' << end<<endl;
		for (long long j = start; j <= end; j++)
		{
			for (int m = 3; m <= 6; m++)//3n to 6n compared against 2n
			{
				twoxvec = itov(2 * j);//set (and reset 2n)
				mxvec = itov(m*j);
				if (!is_permutation(mxvec.begin(), mxvec.end(), twoxvec.begin()))
					goto NewJ;
				/*//old perm check
				for (int k = 0; k <= i; k++)
				{
					for (int l = 0; l <= i; l++)
					{
						if (mxvec[k] == twoxvec[l])
						{
							twoxvec[l] = -1;
							break;
						}
						if (l == i)
							goto NewJ;
					}
				}
				//*/
			}//sol passes thru this '}'
			cout << j << endl;
			return 0;
			NewJ:;
		}
	}


	return 0;
}