#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 501; 

void first(int n, vector<vector<int>> &graph)
{
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ )
			{
				graph[i][j] = INF;
			}
	}
	for ( int i = 1; i <= n; i++ )
	{
		graph[i][i] = 0;
	}
}

void calc(int n, vector<vector<int>> &graph)
{
	for ( int k = 1; k <= n; k++ ) {
		for ( int i = 1; i <= n; i++ ) {
			for ( int j = 1; j <= n; j++ ) {
				int cost = graph[i][k] + graph[k][j];
				 graph[i][j] = min(graph[i][j], cost);
			}
		}
	}
}

int countNum(int student, int n, vector<vector<int>> &graph)
{
	int i = 1, cnt = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( student != i && graph[student][i] == INF && graph[i][student] == INF )
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n, m;
	int ans = 0;
	vector<vector<int>> graph(INF, vector<int>(INF));
	
	cin >> n >> m;
	first(n, graph); 
	while ( m-- )
	{
		int a, b; cin >> a >> b;
		graph[a][b] = 1; 
	}
	
	calc(n, graph);
	for ( int i = 1; i <= n; i++ )
	{ 
		ans += countNum(i, n, graph);
	}
	
	cout << ans << '\n';
	return 0;
}