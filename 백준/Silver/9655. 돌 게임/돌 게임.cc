#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

    cin >> N;

	if (N % 2 == 1) {	// 돌이 홀수개면 상근이가 이김
		cout << "SK";
	}
	else {		// 짝수 개면 창영이가 이김
		cout << "CY";
	}

	return 0;
}