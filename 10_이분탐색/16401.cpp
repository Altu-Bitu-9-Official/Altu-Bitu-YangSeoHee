#include <iostream>
#include <vector>

using namespace std;

#define MAX_SNACK 1000000000

int bs(int m, vector<int> &snack)
{
    int right = MAX_SNACK; 
    int left = 1;          
    int ans = 0;

    while ( left <= right )
    {
        int mid = (left + right) / 2;
        int cnt = 0;
        
        for ( int i = 0; i < snack.size(); i++)
        {
            cnt += snack[i] / mid;
        }
        if ( cnt >= m )
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> snack(n);

    for ( int i = 0; i < n; i++ )
    {
        cin >> snack[i];
    }

    cout << bs(m, snack);
    return 0;
}