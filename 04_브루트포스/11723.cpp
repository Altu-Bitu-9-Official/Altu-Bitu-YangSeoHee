#include <iostream>
#include <string>

using namespace std;

int main()
{
	int M;
	cin >> M;
	int S = 0; //비트마스킹

	string cmd;
	string out;

	
	for ( int i = 0; i < M; i++ )
	{
		cin >> cmd;

		if ( cmd == "add" )
		{
			int x;
			cin >> x;
			S |= (1 << (x - 1)); //x번째 비트를 1로 만들고 원소 추가
		}
		else if ( cmd == "remove" )
		{
			int x;
			cin >> x;
			S &= ~(1 << (x - 1)); //x번째 비트를 0으로 만들고 원소 제거
		}
		else if ( cmd == "check" )
		{
			int x;
			cin >> x;
			out += (S & (1 << (x - 1))) ? "1\n" : "0\n"; //x번째 비트가 1인지 확인
			//결과가 1이면 있음, 0이면 없음
		}
		else if ( cmd == "toggle" )
		{
			int x;
			cin >> x;
			S ^= (1 << (x - 1)); //x번째 비트를 반전시킴(있으면 0, 없으면 1)
		}
		else if ( cmd == "all" )
		{
			S = (1 << 20) - 1; //20개 비트 전부 다 1
		}
		else
		{
			S = 0; //전부 0으로
		}
	}
	cout << out;
}