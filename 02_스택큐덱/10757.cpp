#include <iostream>
#include <string>
#include <stack>
#include <deque>

int main()
{
	std::string A, B;
	std::cin >> A >> B;

	std::stack<int> num_a, num_b; //자릿수 스택
	for ( char ch : A ) //문자를 정수로 바꿔서 스택에 넣기
		num_a.push(ch - '0');
	for ( char ch : B )
		num_b.push(ch - '0');

	std::deque<int> result;
	int carry = 0;

	while ( !num_a.empty() || !num_b.empty() || carry )
	{
		int aa = 0; //A의 현재 자릿수
		if ( !num_a.empty() ) //자릿수 스택이 비어있으면
		{
			aa = num_a.top(); //A의 마지막값 꺼내기, 자릿수 스택 마지막에 있는 것 LIFO
			num_a.pop();
		}

		int bb = 0;
		if ( !num_b.empty() )
		{
			bb=num_b.top();
			num_b.pop();
		}

		int sum = aa + bb + carry;
		result.push_front(sum % 10);
		carry = sum / 10;
	}

	for ( int n : result )
		std::cout << n;
}