#include <iostream>
#include <vector>

using namespace std;

const int N = 19;

int dr[4] = { 0,1,1,-1 };
int dc[4] = { 1,1,0,1 };

bool inRange(int r, int c)
{
	return (0 <= r && r < N && 0 <= c && c < N);
}

int dfs(const vector<vector<int>> &board, int r, int c, int direction, int color)
{
	int newr = r + dr[direction];
	int newc = c + dc[direction];

	if ( !inRange(newr, newc) || board[newr][newc] != color )
		return 1;

	return (1 + dfs(board, newr, newc, direction, color));
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>> board(N, vector<int>(N));

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < N; j++ )
			cin >> board[i][j];
	}

	for ( int r = 0; r < N; r++ )
	{
		for ( int c = 0; c < N; c++ )
		{
			if ( board[r][c] == 0 ) continue;

			int color = board[r][c];

			for ( int dir = 0; dir < 4; dir++ )
			{
				int prevr = r - dr[dir];
				int prevc = c - dc[dir];

				if ( inRange(prevr, prevc) && board[prevr][prevc] == color ) continue;

				int cnt = dfs(board, r, c, dir, color);

				if ( cnt != 5 ) continue;

				int plusr = r;
				int plusc = c;

				for ( int k = 0; k < 5; k++ )
				{
					plusr += dr[dir];
					plusc += dc[dir];
				}
				if ( inRange(plusr, plusc) && board[plusr][plusc] == color ) continue;

				cout << color << "\n";
				cout << r + 1 << " " << c + 1 << "\n";
				return 0;
			}
		}
	}
	cout << 0 << "\n";
	return 0;
}