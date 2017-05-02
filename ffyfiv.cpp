#include "connect3.h"

int ffyfiv()//# of numbers <10000 that do not become palindromic within 50 iterations
{//of adding its reverse to itself (making it a Lychrel number)
	int lychrels = 0;
	for (int n = 1; n < 10000; n++)//
	{
		vector<short> nVec = itov(n);
		cout << n << ' ';
		for (int i = 1; i < 50; i++)
		{			
			vector<short> revn, vsum;
			for (int r = nVec.size() - 1; r >= 0; r--)//create reverse of nVec
			{
				revn.push_back(nVec[r]);
			}
			//vPrint(revn);
			for (int s = 0; s < nVec.size(); s++)//create sum
			{
				vsum.push_back(nVec[s] + revn[s]);
			}
			//vPrint(vsum);
			for (int s = 0; s < vsum.size() - 1; s++)//fix sum by carrying
			{
				vsum[s + 1] += vsum[s] / 10;
				vsum[s] = vsum[s] % 10;
			}
			if (vsum[vsum.size() - 1] / 10 > 0)//carry final digit if necessary
			{
				vsum.push_back(vsum[vsum.size() - 1] / 10);
				vsum[vsum.size() - 2] %= 10;
			}
			//vPrint(vsum);
			if (isPalindrome(vsum))
				goto nextN;
			else
				nVec = vsum;
		}
		lychrels++;
		cout << 'L';
		nextN:;
		cout << endl;
	}
	cout << endl << lychrels << endl;
	return 0;
}