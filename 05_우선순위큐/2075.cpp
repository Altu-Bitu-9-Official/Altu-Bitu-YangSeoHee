#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); //시간초과 방지..

	int N;
	cin >> N;

	priority_queue<long long, vector<long long>, greater<long long>> num;
	//최소 힙, 작은 값이 top

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < N; j++ )
		{
			long long x;
			cin >> x;

			num.push(x);
			if ( (int)num.size() > N )
				num.pop(); //작은 값 제거
		}
	}
	cout << num.top() << '\n'; //최솟값이 전ㄴ체에서 N번째 큰 수가 된다ㅏ
}