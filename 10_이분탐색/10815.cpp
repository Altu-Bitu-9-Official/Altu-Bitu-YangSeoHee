#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int bs(int num, vector<int> &card, int n)
{
	int left = 0; int right = n - 1;
	while ( left <= right )
	{
		int mid = (left + right) / 2;
		if ( num == card[mid] )
		{
			return 1;
		}
		if ( num > card[mid] )
		{
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return 0;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, num;
	cin >> n;
	vector<int> card(n);
	for ( int i = 0; i < n; i++ )
	{
		cin >> card[i];
	}
	sort(card.begin(), card.end()); // 이분 탐색을 위해 정렬

	cin >> m;
	while ( m-- )
	{
		cin >> num;
		cout << bs(num, card, n)<<' ';
	}

	return 0;
}