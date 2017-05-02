int sixty()//find sets of 5 primes where taking any 2 and concatenating creates a prime
{//find min sum of such sets
	vector<bool> primality(1000000, true);
	primality[0] = false; primality[1] = false;
	for (int i = 2; i <= sqrt(primality.size()); i++)//find primes with sieve
	{
		if (!primality[i])
			continue;
		for (int j = 2 * i; j < primality.size(); j += i)
			primality[j] = false;
	}
	vector<int> primes;
	primality[2] = false, primality[5] = false;//don't want 2 or 5 (can't make prime when cpncat to end)
	for (int i = 0; i < primality.size(); i++)//transfer primes to vector of only primes
		if (primality[i])
			primes.push_back(i);
	cout << "primed." << "\n\n";
	
	vector<vector<int>> setsof4;
	vector<int> set;
	int ind = 0, sum = 0;

	//finding sets of 5 was super slow so find sets of 4 instead (Part1) and then try to grow those by 1 (Part2)
	//PART 1
	//*
	const int max = 1000;//arbitrary largish number
	while (setsof4.size() < 50)//50 is also a largish guesstimate
	{//create sets
		if (ind >= max)
		{
			while (set.back() < primes[ind])//unsticks sets by reverting them and continuing
				ind--;
			set.pop_back();
			ind++;
		}
		set.push_back(primes[ind]);
		ind++;
		for (int p1 = 0; p1 < set.size(); p1++)//check that all concats are prime
		{
			for (int p2 = 0; p2 < set.size(); p2++)
			{
				if (p1 == p2)
					continue;
				if (!isPrime(concatInts(set[p1], set[p2])))
				{
					set.pop_back();
					goto NextSet;
				}
			}
		}
		if (set.size() == 4)//sets of 4 enter here
		{
			setsof4.push_back(set);
			for (int p : set)
				cout << p << ' ';
			cout << "<<" << endl;
			ind = max;//causes set to continue to next ones
		}
	NextSet:;
	}
	//*/

	cout << endl << endl;

	//PART 2  
	//*
	
	cout << "attempting to extend each previous set an additional prime..." << endl;
	const int max2 = 2000;//arbitrary somewhat larger large number
	ind = 0;
	for (int s = 0; s < setsof4.size(); s++)
	{
		cout << s + 1 << endl;
		set = setsof4[s];
		while (set.back() >= primes[ind])//get ind up to speed
			ind++;
	NextSet2:;
		if (ind >= max2)
		{
			ind = 0;
			continue;
		}
		set.push_back(primes[ind]);
		ind++;
		for (int p1 = 0; p1 < set.size() - 1; p1++)//for each prime in set besides last
		{//concat to last both ways and ensure prime
			int bonus = set.back();
			if (!isPrime(concatInts(set[p1], bonus)) || !isPrime(concatInts(bonus, set[p1])))
			{
				set.pop_back();
				goto NextSet2;
			}
		}//sets of 5 go thru this '}'
		sum = 0;
		for (int p : set)
		{
			cout << p << ' ';
			sum += p;
		}
		cout << "<<" << endl << sum << endl;
		//break;
	}
	//*/
	return 0;
}
