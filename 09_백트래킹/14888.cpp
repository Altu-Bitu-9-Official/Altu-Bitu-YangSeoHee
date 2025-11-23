#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX_N = 11;
const int ADD = 0, SUB = 1, MUL = 2, DIV = 3;
const int EXP_NUM = 4; //연산자 개수

int n;
int nums[MAX_N]; //입력 숫자들
int expression[EXP_NUM]; //연산자 개수
int max_val = -INF, min_val = INF;

void backtrack(int cnt, int cur_val)
{
	if ( cnt == n - 1 )
	{
		max_val = max(max_val, cur_val);
		min_val = min(min_val, cur_val);
		return;
	}

	for ( int i = 0; i < EXP_NUM; i++ )
	{
		if ( expression[i] == 0 ) continue;

		expression[i]--;
		
		switch ( i )
		{
		case ADD :
			backtrack(cnt + 1, cur_val + nums[cnt + 1]);
			break;
		case SUB :
			backtrack(cnt + 1, cur_val - nums[cnt + 1]);
			break;
		case MUL :
			backtrack(cnt + 1, cur_val * nums[cnt + 1]);
			break;
		case DIV :
			backtrack(cnt + 1, cur_val / nums[cnt + 1]);
			break;
		}

		expression[i]++;
	}
}

int main()
{
	cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		cin >> nums[i];
	}
	for ( int i = 0; i < EXP_NUM; i++ )
	{
		cin >> expression[i];
	}
	backtrack(0, nums[0]);

	cout << max_val << '\n' << min_val;

	return 0;
}