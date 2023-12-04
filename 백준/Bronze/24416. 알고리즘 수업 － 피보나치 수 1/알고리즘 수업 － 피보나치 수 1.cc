#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int f[41];
int c1, c2;

int fib(int n) {
	if (n == 1 || n == 2) {
		c1++;		// 코드1 실행횟수 카운트
		return 1;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

int fibonacci(int n) {
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) {
		c2++;	// 코드2 실행횟수 카운트
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	fib(n);		// 코드1 실행횟수 계산
	fibonacci(n);		// 코드2 실행횟수 계산
	cout << c1 << " " << c2;

	return 0;
}