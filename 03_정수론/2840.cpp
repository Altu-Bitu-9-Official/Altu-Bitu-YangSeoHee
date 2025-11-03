#include <iostream>      
#include <vector>       
#include <string> 

using namespace std;

int main()
{
    int N, K;                           // N ¹ÙÄû Ä­ ¼ö, K ¹ÙÄû µ¹¸®´Â È½¼ö
    cin >> N >> K;

    vector<char> wheel(N, '?');         
    vector<int> arrowP(26, -1);         
    int arrow = 0;                       
    bool ok = true; 

    for ( int i = 0; i < K; ++i )
    {
        int s; char c;
        cin >> s >> c;                  // sÄ­ ½Ã°è¹æÇâ È¸Àü, È­»ìÇ¥ Ä­Àº c

        arrow = (arrow + s) % N;            

        
        if ( wheel[arrow] != '?' && wheel[arrow] != c )
        {
            ok = false;
        }

       
        if ( arrowP[c - 'A'] != -1 && arrowP[c - 'A'] != arrow )
        {
            ok = false;
        }

        
        wheel[arrow] = c;
        arrowP[c - 'A'] = arrow;
    }

    if ( !ok )
    {
        cout << "!\n";                  
        return 0;
    }

    
    string rst;
    for ( int i = 0; i < N; ++i )
    {
        int idx = (arrow - i) % N;        
        if ( idx < 0 )
        {
            idx += N;
        }
        rst.push_back(wheel[idx]);
    }
    cout << rst << '\n';
    return 0;
}
