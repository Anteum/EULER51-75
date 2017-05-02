#include "connect3.h"

class CFExactRem//let the expression being converted to a continuous fraction be x
{//this class is a container for x - (the current continuous fraction approx of x)
//and is represented in the form (sqrt(num) + sum) / div
public:
	CFExactRem(int num, int summer = 0, int divider = 1)//constructor
	{
		n = num;
		sum = summer;
		div = divider;
		x = sqrt(n);
	}
	int takeStep()//takeStep outputs next coefficient and calculates new CFExactRem 
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
vector<short> rootnCFRep(int n)//sqrt(n) continued fraction representation: [a0; a1, a2,...]
{
	vector<short> rep;
	CFExactRem expr{ n };
	int a0 = expr.takeStep();
	double test = sqrt(n) - int(sqrt(n));//will be 0 when n is a square number
	rep.push_back(a0);
	if (test == 0.0)//square numbers dont have/need a CF rep
		return rep;
	int a = 0;
	while (a != 2 * a0)//when a == 2 * a0, is when the period of a sqrt(n) CF rep ends
	{
		a = expr.takeStep();
		rep.push_back(a);
	}

	return rep;
}


int sxyfor()//all square roots are periodic when written as continued fractions
{//how many continued fractions' period's lengths are odd with sqrt(N) <= sqrt(10000)
	
	int oddPeriodSum = 0;
	for (int i = 1; i <= 10000; i++)
	{
		if (rootnCFRep(i).size() % 2 == 0)//first value in rootnCFRep is not inside the period
			oddPeriodSum++;//so an even length makes for an odd period
		//cout << i << "  ";
	}
	cout << endl << oddPeriodSum << endl;
	
	return 0;
}