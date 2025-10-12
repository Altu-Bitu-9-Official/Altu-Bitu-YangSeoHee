#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	const int MAX = 1000000;
	vector<int> isPrime(MAX + 1, true);
	isPrime[0] = isPrime[1] = false;

	for ( int i = 2; i * i <= MAX; ++i )
	{
		if ( isPrime[i] )
		{
			for ( int j = i * i; j <= MAX; j += i )
			{
				isPrime[j] = false;
			}
		}
	}

	//시간초과 해결
	vector<int> primes;
	for ( int i = 2; i <= MAX; ++i )
	{
		if ( isPrime[i] )
		{
			primes.push_back(i);
		}
	}

	int n;
	while ( cin >> n && n != 0 )
	{
		bool found = false;

		for ( int p:primes)
		{
			if ( p > n / 2 ) break;
			if ( isPrime[n - p] )
			{
				cout << n << " = " << p << " + " << (n - p) << '\n';
				found = true;
				break;
			}
		}
		if ( !found )
		{
			cout << "Goldbach's conjecture is wrong.";
		}
	}
	return 0;
	
}