#include <iostream>
#include <string>
using namespace std;

int countHamburger(int n, int k, string &str)
{
    int cnt = 0;
    for ( int i = 0; i < n; i++ )
    {
        if ( str[i] != 'P' )
        {
            continue;
        }

        for ( int j = i - k; j <= i + k; j++ )
        {
            if ( j < 0 || j > n - 1 )
            {
                continue;
            }

            if ( str[j] == 'H' )
            {
                cnt++;
                str[j] = 'O';
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    int n, k;
    string s;

    cin >> n >> k >> s;
    cout << countHamburger(n, k, s) << "\n";

    return 0;
}