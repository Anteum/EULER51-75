#include "connect3.h"

vector<short> vFact(int n)
{
	vector<short> fact = itov(n);
	for (int i = n - 1; i > 0; i--)
	{
		fact = multVecs(fact, itov(i));
	}
	return fact;
}

long long factorial (int n)//factorial function (n!) //only for n<=20
{
	if (n > 1)
		return (n * factorial (n-1));
	else
		return 1;
}

bool isPrime(long long n)
{
	if (n == 1)
		return false;
	if(n==2||n==3||n==5||n==7)
		return true;
	if(n%2==0)
		return false;
	if(n%3==0)
		return false;
	if(n%5==0)
		return false;
	if(n%7==0)
		return false;
	for (int i = 11; i < n / 10; i += 2)
		if (n%i == 0)
			return false;
	return true;
}

template<typename T>
void vPrint(vector<T> digits)
{
	for (int ind = 0; ind < digits.size(); ind++)
		cout << digits[ind] << ' ';
	cout<<endl;
}
template void vPrint(vector<short>);
template void vPrint(vector<int>);

int numLength(long long i)
{
	int n=1;
	while(i>=10)
	{
		n++;
		i/=10;
	}
	return n;
}

vector<short> itov(long long n)
{
	vector<short> digits;
	int length=numLength(n);
	long long order = 1;
	for (int i = 1; i < length; i++)
		order *= 10;
	for (;order>=1;order/=10)
	{
		digits.push_back(n / order);
		while (n >= order)
			n -= order;
	}
	/*
	for(double i=length-1.0;i>=0.0;i-=1.0)
	{
		int temp=pow(10.0,i);
		digits.push_back((n/temp)%10);
	}
	//*/
	return digits;
}

long long vtoi(vector<short> nVector)
{
	long long number = 0, place = 1;
	for(int i=nVector.size()-1;i>=0;i--)
	{
		number+=nVector[i]*place;
		place*=10;
	}
	return number;
}

vector<short> decToBin(int n)
{
	vector<short> binary;
	bool firstdig=false;
	for(int i=19;i>=0;i--)
	{
		if(n>=pow(2,i))
		{
			n-=pow(2,i);
			binary.push_back(1);
			firstdig=true;
		}
		else if(firstdig)
			binary.push_back(0);
	}
	return binary;
}

bool isPalindrome(vector<short> digits)
{
	int leftInd=0,rightInd=digits.size()-1;
	while(leftInd<=rightInd)
	{
		if(digits[leftInd]!=digits[rightInd])
			return false;
		leftInd++,rightInd--;
	}
	return true;
}

vector<short> multVecAndInt(vector<short> cand,int er)
{
	vector<short> product;
	int bonus=0;
	for(int ind=cand.size()-1;ind>=0;ind--)
	{
		bonus+=(cand[ind]*er);
		product.push_back(bonus%10);
		bonus/=10;
	}
	while(bonus>0)
	{
		product.push_back(bonus%10);
		bonus/=10;
	}
	vector<short> reverse;
	for(int i=product.size()-1;i>=0;i--)
		reverse.push_back(product[i]);
	return reverse;
	//create product reversed and reverse right before return
}

bool isPandigital(int n)//use every digit (once) between one and its length
{
	vector<short> num = itov(n);
	vector<short> temp(num.size());//vector with all digits necessary for num's length
	for(int i=0;i<num.size();i++)
	{
		temp[i]=i+1;
	}
	//temp.insert(temp.end(),1,0);
	//bool found;
	for(int i=0;i<num.size();i++)
	{
		for(int j=0;j<temp.size();j++)
		{
			//found=false;
			if(num[i]==temp[j])
			{
				temp[j]=-1;
				//found=true;
				goto NextI;
			}
		}
		//if(found==false)
		return false;
		NextI:;
	}
	return true;
}

void peel_off(vector<short>& mutiny)//take element off front of vector (&delete)
{
	for(int i=0;i<(mutiny.size()-1);i++)
	{
		mutiny[i]=mutiny[i+1];
	}
	mutiny.resize(mutiny.size()-1);
}

int vSum(vector<short> nums)
{
	long long sum=0;
	for(int i=0;i<nums.size();i++)
	{
		sum+=nums[i];
	}
	return sum;
}

vector<int> primeFactors(int n)
{
	vector<int> factors;
	for (;;)
	{
		if (isPrime(n))
		{
			factors.push_back(n);
			return factors;
		}
		for (int x = 2; x <= sqrt(n); x++)
		{
			if (n%x == 0)
			{
				factors.push_back(x);
				n /= x;
				break;
			}
		}
	}
}

template<typename T>
vector<T> uniqEle(vector<T> eles)
{
	vector<T> uniques;
	uniques.push_back(eles[0]);
	for(int n=1;n<eles.size();n++)
	{
		for(int i=0;i<uniques.size();i++)
		{
			if(eles[n]==uniques[i])
				goto NextN;
		}
		uniques.push_back(eles[n]);
		NextN:;
	}
	return uniques;
}
template vector<short> uniqEle(vector<short>);
template vector<int> uniqEle(vector<int>);


vector<short> digOrder(vector<short> num)
{
	vector<short> numOrder = num;
	for (int i = numOrder.size()-1; i > 0; i--)
	{
		if (numOrder[i] > numOrder[i - 1])
		{
			int temp = numOrder[i];//switch digits
			numOrder[i] = numOrder[i - 1];
			numOrder[i - 1] = temp;
			i = numOrder.size();
		}
	}
	return numOrder;
}

vector<short> multVecs(vector<short> cand, vector<short> er)//create return vector backwards
{
	vector<short> prod(cand.size()+er.size(),0);//to be reversed then returned
	vector<short> revprod;
	
	for (int j = er.size()-1; j >= 0; j--)
	{
		int place = 0 + er.size() - 1 - j;
		for (int i = cand.size()-1; i >= 0; i--)
		{
			prod[place] += (cand[i] * er[j]) % 10;
			if (prod[place] > 9)
			{
				prod[place] -= 10;
				prod[place + 1]++;
			}
			prod[place+1] += (cand[i] * er[j]) / 10;
			//prod.push_back(0);
			if (prod[place + 1] > 9)
			{
				prod[place + 1] -= 10;
				prod[place + 2]++;
			}
			place++;
		}
	}
	for (int i = prod.size() - 1; i >= 0; i--)//time to reverse product
	{
		if (i == prod.size() - 1 && prod[i] == 0)//and remove possible leading zero
			i--;
		revprod.push_back(prod[i]);
	}
	return revprod;
}
//*
vector<short> sumVecs(vector <short> and1, vector<short> and2)
{//assume and1 >~ and2
	if (and2.size() > and1.size())
		swap(and1, and2);
	vector<short> sum(and1);
	sum.insert(sum.begin(), 0);
	for (int i = 1; i <= and2.size(); i++)
		sum[sum.size() - i] += and2[and2.size() - i];
	for (int i = 1; i <= sum.size(); i++)
	{
		if (sum[sum.size() - i] >= 10)
		{
			sum[sum.size() - i] -= 10;
			sum[sum.size() - (i + 1)]++;
		}
	}
	if (sum[0] == 0)
		peel_off(sum);
	return sum;
}
//*/
bool vIsGreater(vector<short> a, vector<short> b)//a is greater than or equal to b
{
	if (a.size() > b.size())
		return true;
	else if (b.size() > a.size())
		return false;
	else
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] > b[i])
				return true;
			else if (b[i] > a[i])
				return false;
		}
	return true;//this determines if a is greater when a == b; true for a, false for b
}

long long concatInts(int first, int second)
{
	long long power;
	for (power = 10; second > power; power *= 10)
	{}
	return first*power + second;
}

int eulerPhi(int n)//formula used here is Euler's product formula
{
	long long totatives = 1;
	if (n == 1)
		return totatives;
	vector<int> distinctPrimes = uniqEle(primeFactors(n));
	for (int p = 0; p < distinctPrimes.size(); p++)
		totatives *= (distinctPrimes[p] - 1);
	totatives *= n;
	for (int p = 0; p < distinctPrimes.size(); p++)
		totatives /= distinctPrimes[p];
	return totatives;
}