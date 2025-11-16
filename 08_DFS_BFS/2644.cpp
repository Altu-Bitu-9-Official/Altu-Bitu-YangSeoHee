#include<iostream>
using namespace std;

const int MAX = 100;

int n;
int startNode, targetNode;
int m;
int adj[MAX + 1][MAX + 1];
bool visited[MAX + 1];
int result=-1;

void dfs(int cur, int depth)
{
	if ( cur == targetNode )
	{
		if ( result == -1 || depth < result )
			result = depth;
		return;
	}
	visited[cur] = true;

	for ( int next = 1; next <= n; next++ )
	{
		if ( adj[cur][next] == 1 && !visited[next] )
			dfs(next, depth + 1);
	}
	visited[cur] = false;
}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> startNode >> targetNode;
	cin >> m;

	for ( int i = 0; i < m; i++ )
	{
		int x, y;
		cin >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;

	}

	dfs(startNode, 0);
	cout << result;
	return 0;
}