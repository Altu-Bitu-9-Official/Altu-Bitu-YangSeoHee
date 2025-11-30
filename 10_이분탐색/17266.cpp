#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> light;

bool check(int h)
{
	if ( light[0] - h > 0 )
		return false;

		for ( int i = 1; i < M; i++ )
		{
			int gap = light[i] - light[i - 1];
			if ( gap > 2 * h )
				return false;
		}
	if ( light[M - 1] + h < N )
		return false;

	return true;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	light.resize(M);
	for ( int i = 0; i < M; i++ )
		cin >> light[i];
	int low = 0;
	int high = N;
	int ans = N;

	while ( low <= high )
	{
		int mid = (low + high) / 2;

		if ( check(mid) )
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << ans;
	return 0;
}