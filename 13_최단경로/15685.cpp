#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 100;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };


int Square(vector<vector<bool>> &plane)
{
    int ans = 0;
    for ( int i = 0; i < SIZE; i++ )
    {
        for ( int j = 0; j < SIZE; j++ )
        {
            if ( plane[i][j] && plane[i + 1][j] && plane[i][j + 1] && plane[i + 1][j + 1] )
            {
                ans++;
            }
        }
    }
    return ans;
}

void Dragon(vector<vector<bool>> &plane, int x, int y, int d, int g)
{
    vector<int> dir; 
    plane[y][x] = plane[y + dy[d]][x + dx[d]] = true; 
    x += dx[d];
    y += dy[d];
    dir.push_back(d);
    while ( g-- )
    { 
        int sizeD = dir.size();
        for ( int j = sizeD - 1; j >= 0; j-- )
        { 
            int nextD = (dir[j] + 1) % 4;
            x += dx[nextD];
            y += dy[nextD];
            plane[y][x] = true; 
            dir.push_back(nextD);
        }
    }
}

int main()
{
    int n, x, y, d, g;
    vector<vector<bool>> plane(SIZE + 1, vector<bool>(SIZE + 1, false)); 

   
    cin >> n;

    while ( n-- )
    { 
        cin >> x >> y >> d >> g;
        Dragon(plane, x, y, d, g);
    }

    cout << Square(plane) << '\n';
    return 0;
}