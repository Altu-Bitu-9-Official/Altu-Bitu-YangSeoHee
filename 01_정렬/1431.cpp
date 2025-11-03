#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype> //isdigit 사용

bool cmp(const std::string &a, const std::string &b)
{ //cmp는 두 문자열 비교(a가 b보다 앞에 와야 하는지), bool로 리턴한다
//1. 길이 비교
	if ( a.size() != b.size() )
		return a.size() < b.size();
	//if문으로 길이 비교->cmp로 t/f 리턴

//2. 숫자 합 비교 
	int sa = 0; 
	int sb = 0; //숫자 합 저장할 변수
	for(char c : a) //a의 문자 차례대로 확인
		if(std::isdigit(c))
			sa += c-'0'; //어려움!! c++에서 문자는 아스키코드 값(숫자)으로 저장됨, 0은 48
	for ( char c : b )
		if ( std::isdigit(c) )
			sb += c - '0';

	if ( sa != sb )
		return sa < sb;

//3. 사전 순으로 비교
	return a < b; //숫자가 알파벳보다 사전순으로 작움
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::string> v(N);
	for ( int i = 0; i < N; i++)
		std::cin >> v[i];

	std::sort(v.begin(), v.end(), cmp); //벡터의 첫번쨰 원소 위치, 마지막 원ㅅ 다음 위치, 비교함수 기준으로 정렬하기
	
	for ( int i = 0; i < v.size(); i++ )
		{
			const std::string &s = v[i];
			std::cout << s << '\n';
		}

	return 0;
}

