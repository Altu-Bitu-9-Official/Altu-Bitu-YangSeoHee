#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N, M;
vector<int> nums;
vector<int> seq;

void backtrack(int depth)
{
	if ( depth == M )
	{
		for ( int i = 0; i < M; i++ )
		{
			cout << seq[i] << (i == M - 1 ? '\n' : ' ');
		}
		return;
	}
	int prev = -1;
	for ( int i = 0; i < N; i++ )
	{
		if ( nums[i] == prev ) continue;
		prev = nums[i];

		seq.push_back(nums[i]);
		backtrack(depth + 1);
		seq.pop_back();
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	nums.resize(N);
	for ( int i = 0; i < N; i++ ) cin >> nums[i];

	sort(nums.begin(), nums.end());

	backtrack(0);

	return 0;
}