#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int miain()
{
	ios::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> D(N), H(N);
	for ( int i = 0; i < N; i++ )
		cin >> D[i] >> H[i];

	vector<queue<int>> line(M);
	for ( int i = 0; i < N; i++ )
		line[i % M].push(i); //ÁÙ¼­±â
}