#include <iostream>
#include <numeric>

using namespace std;

long long absl(long long x)
{
	return x >= 0 ? x : -x;
}

int main()
{
	int N; //동생 수
	long long S; //수빈 시작 위치
	cin >> N >> S;

	long long res = 0;
	for ( int i = 0; i < N; ++i )
	{
		long long A;
		cin >> A;
		long long D = absl(A - S);
		res = std::gcd(res, D);
	}
	cout << res << '\n';
	return 0;
}