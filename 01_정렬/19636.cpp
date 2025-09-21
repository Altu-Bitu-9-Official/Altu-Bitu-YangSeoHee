#include <iostream>

//계속 문제랑 출력이 안 맞은 이유 : floor_div:c++ 정수 나눗셈은 음수에서 작은 쪽으로 버림.. floor_div 써야함

long long floor_div(long long a, long long b)
{
	if ( a >= 0 )
		return a / b;
	else return (a - (b - 1)) / b; //버림!!!!!ㅠㅠㅠㅠ
}

int main()
{
	long long W0, I0, T; //다이어트 전 체중, diet 전 일일에너지 섭취량, 역치
	std::cin >> W0 >> I0 >> T;

	int D; //다이어트 기간
	long long I, A; //diet ing 일일에너지 섭취량, diet ing 일ㄹ일활동 대사량
	std::cin >> D >> I >> A;

	//1.기초대사량 변화 고려x...
	{
		long long weight = W0;
		long long BMR = I0; //BMR=기초대사량 변화 없음
		bool dead = false;

		for ( int day = 1; day <= D; ++day )
		{
			long long C = BMR + A; //에너지 소비량 = 기초대사량+활동대사량
			long long plusWeight = I - C; //체중 ++
			weight += plusWeight;
			if ( weight <= 0 )
			{
				dead = true;
				break;
			}
				
		}

		if ( dead )
			std::cout << "Danger Diet\n";
		else
			std::cout << weight << ' ' << BMR << "\n";
	}

	//2.기초대사량 변화 고려o
	{
		long long weight = W0;
		long long BMR = I0; //BMR=기초대사량 변화 있음
		bool dead = false;

		for ( int day = 1; day <= D; ++day )
		{
			long long C = BMR + A; //에너지 소비량 = 기초대사량+활동대사량
			long long plusWeight = I - C; //체중 ++
			weight += plusWeight;
			if ( weight <= 0 )
			{
				dead = true;
				break;
			}


			long long abs_plusWeight = (plusWeight >= 0 ? plusWeight : -plusWeight);
			if ( abs_plusWeight > T )
			{
				long long plusBMR = floor_div(plusWeight, 2); //floor_div 적용
				BMR += plusBMR;
			}

			if ( BMR <= 0 )
			{
				dead = true;
				break;
			}
		}

		if ( dead )
			std::cout << "Danger Diet\n";
		else
			std::cout << weight << ' ' << BMR << ' ' << (I0 > BMR ? "YOYO" : "NO") << "\n";
	}

}

