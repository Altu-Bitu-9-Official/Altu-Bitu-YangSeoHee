#include <iostream>

using namespace std;

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	int e = 1;
	int s = 1;
	int m = 1;
	int year = 1;

	while ( true )
	{
		if ( e == E && s == S && m == M )
		{
			break;
		}

		++year;
		++e;
		++s;
		++m;

		if ( e == 16 ) e = 1;
		if ( s == 29 ) s = 1;
		if ( m == 20 ) m = 1;
	}

	cout << year << '\n';
}