#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007; //오버플로우

int methodNum(int n)
{
	vector<int> dp(n + 1);

	dp[1] = 1;
	dp[2] = 2;

	for ( int i = 3; i <= n; i++ )
	{
		int vertical = dp[i - 1];
		int horizontal = dp[i - 2]; //피보나치
		dp[i] = (vertical + horizontal) % MOD;
	}
	return dp[n];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << methodNum(n);

	return 0;
}