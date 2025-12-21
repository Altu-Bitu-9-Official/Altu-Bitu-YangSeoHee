#include <iostream>
#include <vector>

using namespace std;

const int CLEAN = 2;

int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 }; 

int clean(int n, int m, int r, int c, int d, vector<vector<int>> &board)
{
    int cnt = 0;

    while ( true )
    {
        if ( board[r][c] != CLEAN )
        {
            cnt++;
        }
        board[r][c] = CLEAN;

        bool find = false; 
        for ( int i = 0; i < 4; i++ )
        {
            int nd = (d - i + 3) % 4;
            int nr = r + dy[nd], nc = c + dx[nd];

            if ( board[nr][nc] == 0 )
            { 
                find = true;
                r = nr; c = nc; d = nd;
                break;
            }
        }
        if ( find )
        { 
            continue;
        }

        
        int bd = (d + 2) % 4;
        int br = r + dy[bd], bc = c + dx[bd];

       
        if ( board[br][bc] == 1 )
        {
            return cnt;
        }
        
        r = br; c = bc;
    }
    return cnt;
}


int main()
{
    int n, m, r, c, d;
    vector<vector<int>> board;

    
    cin >> n >> m;
    cin >> r >> c >> d;
    board.assign(n, vector<int>(m, 0));
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < m; j++ )
        {
            cin >> board[i][j];
        }
    }

   
    cout << clean(n, m, r, c, d, board);

    return 0;
}