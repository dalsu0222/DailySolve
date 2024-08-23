#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
long long x, y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;
	long long  z = y * 100 / x;
	if (z >= 99) {
		cout << -1;
		return 0;
	}
	// 실수 연산 대신 정수 연산으로 수정
	long long left = (z + 1) * x - 100 * y;
	long long right = 99 - z;
	long long result = (left + right - 1) / right;  // 올림 대신 정수 나누기로 계산, 부동소수점 오차 피하기
	cout << result;

	return 0;
}
