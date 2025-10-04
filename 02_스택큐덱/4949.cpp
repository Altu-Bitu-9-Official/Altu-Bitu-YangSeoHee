#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::string line;
	while ( true )
	{
		if ( !getline(std::cin, line) ) //더 읽을 줄이 없으면
			break;
		if ( line == "." ) //.이면
			break;

		std::stack<char> ch;
		bool balance = true;

		for ( char c : line )
		{
			if ( c == '(' || c == '[' )
			{
				ch.push(c);
			}
			else if ( c == ')' || c == ']' )
			{
				if ( ch.empty() ) //다른 거 없으면
				{
					balance = false;
					break;
				}

				char top = ch.top();
				ch.pop(); //꺼내기
				if ( (c == ')' && top != '(') || (c == ']' && top != '[') )
				{ //짝이 서로 다르면
					balance = false;
					break;
				}
			}
		}
		std::cout << ((balance && ch.empty()) ? "yes" : "no") << '\n';
	}
	return 0;
}
