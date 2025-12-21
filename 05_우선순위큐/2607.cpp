#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	string first;
	cin >> first;

	int cnt[26] = { 0 }; //first 알파벳 개수
	for ( char ch : first )cnt[ch - 'A']++;

	int ans = 0;
	for ( int i = 1; i < N; i++ )
	{
		string word;
		cin >> word;

		int compare[26];
		for ( int j = 0; j < 26; j++ ) compare[j] = cnt[j];
		for ( char ch : word ) compare[ch - 'A']--; //first랑 word 단어 개수 비교. 빼기

		int left = 0;
		int lack = 0;
		for ( int j = 0; j < 26; j++ )
		{
			if ( compare[j] > 0 )
			{
				left += compare[j]; //first에서 남은 글자
			}
			else
				lack += -compare[j]; //first에서 부족한 글자
		}

		if ( (left == 0 && lack == 0) || (left == 1 && lack == 0) ||
			(left == 0 && lack == 1) || (left == 1 && lack == 1) )
		{
			ans++;
		}
	}
	cout << ans << '\n';
}