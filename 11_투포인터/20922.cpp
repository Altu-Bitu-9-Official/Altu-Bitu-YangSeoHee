#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX_NUM = 100001;  


int MaxLength(vector<int> seq, int k, int n)
{
    int ans = 1;  
    int left = 0, right = 1;  
    vector<int> count(MAX_NUM, 0);  
    count[seq[left]]++; 

    
    while ( right < n )
    {
        
        if ( count[seq[right]] >= k )
        { 
            count[seq[left]]--;  
            left++;  
            continue; 
        }

       
        count[seq[right]]++;  
        right++;  
        ans = max(ans, right - left);  
    }

    return ans;
}

int main()
{
    int n, k;


    cin >> n >> k;
    vector<int> seq(n, 0);
    for ( int i = 0; i < n; i++ )
    {
        cin >> seq[i];
    }

    
    cout << MaxLength(seq, k, n);

    return 0;
}