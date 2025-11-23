#include <iostream>

using namespace std;

pair<int, int> li[12];

int area()
{
	int bigS;
	int smallS;
	for ( int i = 0; i < 9; i++ )
	{
		if ( li[i].first == li[i + 2].first && li[i + 1].first == li[i + 3].first )
		{
			bigS = (li[i].second + li[i + 2].second) * (li[i + 1].second + li[i + 3].second);
			smallS = li[i + 2].second * li[i + 1].second;
		}
	}
	return bigS - smallS;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k;
	cin >> k;

	int dir, len;
	for ( int i = 0; i < 6; i++ )
	{
		cin >> dir >> len;
		li[i] = { dir, len };
	}

	for ( int i = 0; i < 6; i++ )
	{
		li[i + 6] = li[i];
	}

	int a = area();
	cout << k * a;

	return 0;
}
	