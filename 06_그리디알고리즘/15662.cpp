#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> face;
vector<pair<int, int>> stack;
vector<int> num;

void check_rotation(int currentNum, int currentDir)
{
    if ( currentNum - 1 >= 0 && num[currentNum - 1] == 0 )
    {
        if ( face[currentNum][6] != face[currentNum - 1][2] )
        { 
            stack.push_back(make_pair(currentNum - 1, currentDir * -1));
            num[currentNum - 1] = 1;
            check_rotation(currentNum - 1, currentDir * -1);
        }
    }
    if ( currentNum + 1 < face.size() && num[currentNum + 1] == 0 )
    {
        if ( face[currentNum][2] != face[currentNum + 1][6] )
        { 
            stack.push_back(make_pair(currentNum + 1, currentDir * -1));
            num[currentNum + 1] = 1;
            check_rotation(currentNum + 1, currentDir * -1);
        }
    }
}

int main()
{
    int t;
    int k;

    cin >> t; 

    face.resize(t); 
    for ( int i = 0; i < t; ++i )
        cin >> face[i];

    cin >> k; 
    for ( int i = 0; i < k; ++i )
    { 
        int n, d; //개수,방향
        cin >> n >> d; 
        stack.clear();
        stack.push_back(make_pair(n - 1, d));
        num.assign(t, 0); 
        num[n - 1] = 1;
        check_rotation(n - 1, d);

        while ( !stack.empty() )
        {
            pair<int, int> top = stack.back();
            stack.pop_back();
            int tmpNum = top.first;  
            int tmpDir = top.second; 
            if ( tmpDir == 1 )
            { // 시계방향
                face[tmpNum] = face[tmpNum].back() + face[tmpNum].substr(0, 7);
            }
            else
            { // 반시계방향
                face[tmpNum] = face[tmpNum].substr(1) + face[tmpNum][0];
            }
        }
    }

    int cnt = 0;
    for ( int i = 0; i < t; ++i )
    {
        if ( face[i][0] == '1' )
        {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}