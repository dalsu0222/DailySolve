#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int money;
int cnt;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> money;
	money = 1000 - money;	// 1000엔을 내고 남은 거스름돈을 잔돈으로 저장
	while (money > 0) {
		if (money >= 500)
			money -= 500;
		else if (money >= 100)
			money -= 100;
		else if (money >= 50)
			money -= 50;
		else if (money >= 10)
			money -= 10;
		else if (money >= 5)
			money -= 5;
		else if (money >= 1)
			money -= 1;
		
		cnt++;		// 동전 개수 1개 증가
	}

	cout << cnt;

	return 0;
}
