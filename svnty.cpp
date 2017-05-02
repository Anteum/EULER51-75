#include "connect3.h"

int svnty()//find n, 1<n<10000000, where phi(n) is a perm of n and n/phi(n) is minimum
{
	double min = 6, value;
	int minsN;
	vector<short> nVec, phiVec;
	for (int n = 2; n < 10000000; n++)//10 000 000...
	{
		nVec = itov(n), phiVec = itov(eulerPhi(n));
		if (nVec.size() > phiVec.size())//phiVec's size can't be greater than nVec's due to def of phi(n)
			continue;
		if (is_permutation(nVec.begin(), nVec.end(), phiVec.begin()))
		{
			value = double(n) / eulerPhi(n);
			if (value < min)
			{
				min = value;
				minsN = n;
				cout << min << "  " << minsN << endl;
			}
		}
	}
	//cout << min << "  " << minsN << endl;

	return 0;
}