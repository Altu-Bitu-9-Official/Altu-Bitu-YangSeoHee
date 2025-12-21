#include <iostream>
#include <vector>
#include <map>

using namespace std;


int MaxSushi(vector<int> &belt, int n, int a, int b, int c)
{
    vector<int> sushi(a + 1, 0);  

    int cntS = 1; 
    sushi[c]++;

    for ( int i = 0; i < b; i++ )
    {
        if ( !sushi[belt[i]] ) cntS++;
        sushi[belt[i]]++;
    }

    int ans = cntS; 
    
    for ( int i = b; i < n + b; i++ )
    {  
        int out = belt[(i - b) % n];
        sushi[out]--;
        if ( sushi[out] == 0 ) cntS--;

        int in = belt[i % n];
        sushi[in]++;
        if ( sushi[in] == 1 ) cntS++;

        ans = max(ans, cntS);
    }

    return ans;
}


int main()
{
    int n, a, b, c;

   
    cin >> n >> a >> b >> c;
    vector<int> belt(n, 0);
    for ( int i = 0; i < n; i++ )
    {
        cin >> belt[i];
    }
    cout << MaxSushi(belt, n, a, b, c);

    return 0;
}