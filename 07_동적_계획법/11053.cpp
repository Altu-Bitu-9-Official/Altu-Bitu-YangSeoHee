#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxIncrease(int n, vector<int>& sequence)
{
	//수열 길이 n, 수열 sequence
	vector<int> ans(n, 1);

	for ( int i = 1; i < n; i++ )
	{
		for ( int j = 0; j < i; j++ )
		{
			if ( sequence[i] > sequence[j] )
			{
				ans[i] = max(ans[i], ans[j] + 1); //new 최대
			}
		}
	}
	return *max_element(ans.begin(), ans.end());
}

int main()
{
	int n;
	cin >> n;

	vector<int> sequence(n);
	for ( int i = 0; i < n; i++ )
	{
		cin >> sequence[i];
	}
	cout << MaxIncrease(n, sequence);

	return 0;
}