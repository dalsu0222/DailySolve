#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int time = 9;	// 최솟값으로 초기화, "d a l d i dal g o"(8) + "n"(1)
	int repeat = 1;	// "daldidalgo" 최대 반복가능한 횟수

	
	cin >> n;
	// 복사할수록, daldidalgo가 많아져 여러개를 만드는데 시간이 줄어드는 원리
	while (n > 0) {
		n -= repeat;	// "daldidalgo" 반복한만큼 차감
		time++;
		repeat *= 2;
	}

	cout << time;
	
	return 0;
}

/*
	n이 홀수? daldidalgo(8) + daldidalgo(1) + daldidalgo daldida(1) + n(1) = 12
	n이 짝수? daldidalgo(8) + daldidalgo(1) + daldida(1) + n(1) = 11
	n이 짝/홀수냐에 따라서도 계산 가능
*/