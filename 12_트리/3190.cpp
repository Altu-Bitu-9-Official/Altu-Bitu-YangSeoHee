#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

const int EMPTY = 0;
const int APPLE = 0;
const int SNAKE = 0;

int GAME(int n, vector<vector<int>> &board, map<int, char> &cmd)
{
	int dx[4] = { 0, -1, 0, 1 };
	int dy[4] = { 1, 0, -1, 0 };

	deque<ci> snake;
	snake.push_front({ 1, 1 });
	board[1][1] = SNAKE;

	int time = 0;
	int direction = 0;
	while ( true )
	{
		if ( cmd[time] == 'L' )
		{ 
			dir = (dir + 1) % 4;
		}
		else if ( cmd[time] == 'D' )
		{ 
			dir = (dir + 3) % 4;
		}

		time++;

		int nx = snake.front().first + dx[dir];
		int ny = snake.front().second + dy[dir];

		if ( nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == SNAKE )
		{
			break;
		}

		snake.push_front({ nx, ny }); 
		if ( board[nx][ny] != APPLE )
		{ 
			ci tail = snake.back();
			board[tail.first][tail.second] = EMPTY;
			snake.pop_back();
		}
		board[nx][ny] = SNAKE;
	}
	return time;

	}

int main() {
	int n, k, x, y, l, time;
	char c;

	cin >> n >> k;
	vector<vector<int>> board(n + 1, vector<int>(n + 1, EMPTY));
	while ( k-- )
	{
		cin >> x >> y;
		board[x][y] = APPLE;
	}
	cin >> l;
	map<int, char> command;
	while ( l-- )
	{
		cin >> time >> c;
		command[time] = c;
	}
	cout << GAME(n, board, c);
	return 0;
}


