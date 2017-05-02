#include "connect3.h"

int ffythr()//# of values of nCr > 1 000 000, 1<=n<=100
{//nCr=n!/(r!(n-r)!)
	
	int millions = 0;
	for (int n = 23; n <= 100; n++)
	{
		if (n % 2 == 0)//all middle values >1000000 with n>=23
			millions++;
		int mid = n / 2 + 1;
		for (int r = mid; r <= n; r++)
		{//nCr>1000000<==>n!>(r!(n-r)!)*1000000
			if (vIsGreater(vFact(n),multVecs(multVecs(vFact(r),vFact(n - r)),itov(1000000))))//factorials get way too large for long long
				millions += 2;//values are symmetrical, (+1 for each side)
			else
				break;
		}
	}
	cout << millions;
	return 0;
}