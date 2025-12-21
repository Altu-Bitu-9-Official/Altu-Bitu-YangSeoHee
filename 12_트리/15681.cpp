#include<iostream>
#include<vector>
#include<map>

using namespace std;


void dfs(int cur, int prev, vector<vector<int>> &tree, vector<int> &dp)
{

	for ( int i = 0; i < tree[cur].size(); i++ )
	{ 
		if ( tree[cur][i] == prev )
		{
			continue;
		}
		dfs(tree[cur][i], cur, tree, dp);
		dp[cur] += dp[tree[cur][i]]; 
	}

	return;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	int n, r, q, u, v;
	cin >> n >> r >> q;

	vector<vector<int>>tree(n + 1, vector<int>(0));

	for ( int i = 0; i < n - 1; i++ )
	{
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	
	vector<int>dp(n + 1, 1);
	dfs(r, 0, tree, dp);

	
	while ( q-- )
	{
		cin >> u;
		cout << dp[u] << '\n';
	}
}