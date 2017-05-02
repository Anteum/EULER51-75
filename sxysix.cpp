#include "connect3.h"

//copied from #64 & #57 and added some 66's
class CFExactRem66
{
public:
	CFExactRem66(int num, int summer = 0, int divider = 1)
	{
		n = num;
		sum = summer;
		div = divider;
		x = sqrt(n);
	}
	int takeStep()
	{
		int temp;
		approx = (x + sum) / div;
		a = approx;
		temp = sum - (div*a);
		sum = 0 - temp;
		div = (n - temp*temp) / div;
		return a;
	}

private:
	int n;
	int sum;
	int div;
	double approx;
	double x;
	int a;
};

vector<short> rootnCFRep66(int n)//
{
	vector<short> rep;
	CFExactRem66 expr{ n };
	int a0 = expr.takeStep();
	double test = sqrt(n) - int(sqrt(n));
	rep.push_back(a0);
	if (test == 0.0)
		return rep;
	int a = 0;
	while (a != 2 * a0)
	{
		a = expr.takeStep();
		rep.push_back(a);
	}
	return rep;
}

class LargeFrac66
{
public:
	vector<short> num;
	vector<short> den;
	void fracDisp()
	{
		for (int n : num)
			cout << n;
		cout << " / ";
		for (int d : den)
			cout << d;
		cout << endl;
	}
};

void contFrac66(LargeFrac66 &frac, int a)
{
	vector<short> temp = multVecAndInt(frac.den, a);
	frac.num = sumVecs(temp, frac.num);
	swap(frac.num, frac.den);
}

int sxysix()//consider equations of form x^2 - D*y^2 = 1; 
{//for (x,y) solutions that minimizes x for a particular D, find for which D<=1000 is x largest
//according to the wiki, the first cont frac (x/y) of sqrt(D) that gives solution to x^2-D*y^2=1, minimizes x
//for this problem, need to find coefficients for CF rep of sqrt(D) and find each step's approximating fraction; so copied help from #64 & #57
	int theD;
	vector<short> x2, y2, x, largestMinX = itov(0);//x2 and y2 are x^2 and y^2
	for (int d = 2; d <= 1000; d++)
	{
		cout << endl << d << " : ";
		vector<short> coeffs = rootnCFRep66(d);//find coefficients for continued fraction of sqrt(D)
		vPrint(coeffs);
		if (coeffs.size() == 1)//d is square and therefore has no (x,y) solutions
			continue;
		
		for (int i = 0; i < 100000; i++)//100000 is arbitrary large number
		{
			LargeFrac66 temp{ itov(0),itov(1) };//starting with 0
			for (int j = i; j >= 1; j--)//i here is how many coefficients beyond the first are used
			{
				int ind = j % (coeffs.size() - 1);//using % to loop around the period of the coefficients when necessary
				if (ind == 0)
					ind = coeffs.size() - 1;
				contFrac66(temp, coeffs[ind]);//
			}
			LargeFrac66 XY{ sumVecs(multVecAndInt(temp.den,coeffs[0]),temp.num),temp.den };// temp + a0
			x = XY.num;
			x2 = multVecs(XY.num, XY.num), y2 = multVecs(XY.den, XY.den);
			if (x2 == sumVecs(itov(1), multVecAndInt(y2, d)))//if (x,y) are solution  (x*x - d*y*y == 1 <==> x*x == 1 + d*y*y)
			{
				if (!vIsGreater(largestMinX,x))//check if x is largest so far and if so remember its d value
				{
					theD = d;
					largestMinX = x;
				}
				break;
			}
		}
	}
	cout << endl << theD << endl;
	
	return 0;
}