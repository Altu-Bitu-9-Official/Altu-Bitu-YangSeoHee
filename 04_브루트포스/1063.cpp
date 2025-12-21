#include <iostream>
#include <string>

using namespace std;

inline bool inside(int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main()
{
	string king, stone;
	int N;
	cin >> king >> stone >> N;

	int kingX = king[0] - 'A'; //凯, A->0, H->7
	int kingY = king[1] - '1'; //青, 1->0,8->7
	int stoneX = stone[0] - 'A';  //凯, A->0, H->7
	int stoneY = stone[1] - '1'; ////青, 1->0,8->7

	for ( int i = 0; i < N; i++ )
	{
		string mv;
		cin >> mv;

		int dx = 0, dy = 0;
		if ( mv == "R" ) { dx += 1; dy = 0; }
		else if ( mv == "L" ) { dx -= 1; dy = 0; }
		else if ( mv == "B" ) { dx = 0; dy -= 1; }
		else if ( mv == "T" ) { dx = 0; dy += 1; }
		else if ( mv == "RT" ) { dx += 1; dy += 1; }
		else if ( mv == "LT" ) { dx -= 1; dy += 1; }
		else if ( mv == "RB" ) { dx += 1; dy -= 1; }
		else if( mv == "LB" ) { dx -= 1; dy -= 1; }

		int kingXMove = kingX + dx;
		int kingYMove = kingY + dy;

		if ( !inside(kingXMove, kingYMove) ) continue;

		if ( kingXMove == stoneX && kingYMove == stoneY )
		{
			int stoneXMove = stoneX + dx;
			int stoneYMove = stoneY + dy;

			if ( !inside(stoneXMove, stoneYMove) ) continue;

			kingX = kingXMove;
			kingY = kingYMove;
			stoneX = stoneXMove;
			stoneY = stoneYMove;
		}
		else
		{
			kingX = kingXMove;
			kingY = kingYMove;
		}
	}

	char kingCol = char('A' + kingX); //凯, 0->A, 7->H
	char kingRow = char('1' + kingY); //青, 0->1, 7->8
	char stoneCol = char('A' + stoneX); //凯, 0->A, 7->H
	char stoneRow = char('1' + stoneY); //青, 0->1, 7->8

	cout << kingCol << kingRow << '\n' << stoneCol << stoneRow << '\n';
}