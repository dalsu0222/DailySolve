#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;
int fib[21];

int fibonacci(int x) {
	// basecase 설정
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	// x번째 피보나치수 반환
	return fibonacci(x-1) + fibonacci(x-2);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> n;
	cout << fibonacci(n);

	return 0;
}