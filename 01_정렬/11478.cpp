#include <iostream>
#include <string>
#include <set>

int main()
{
	std::string S;
	std::cin >> S;

	std::set<std::string> S2; //set : 중복 허용x, 자동 정렬
	//S2 : 부분 문자열 저장할 함수(?)

	for ( int i = 0; i < S.size(); ++i ) //0부터 끝까지
	{
		for ( int len = 1; i + len <= S.size(); ++len ) //1부터 최대 길이까지
		{
			S2.insert(S.substr(i, len)); //i부터 len길이의 부분 문자열 추가, S2에 넣기
		}
	}

std::cout << S2.size() << '\n'; //S2.size()가 서로 다른 부분 문자열 개수!
	return 0;

}