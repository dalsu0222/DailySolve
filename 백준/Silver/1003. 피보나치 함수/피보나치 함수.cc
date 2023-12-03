#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int T;
int fibo[41] = { 0,1, };	// 피보나치 수열

int fibonacci(int n) {
	if (n == 0 || n == 1) {
		return fibo[n];
	}
	else if (fibo[n] == 0) {	// 새로운 피보나치 값 갱신
		fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return fibo[n];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			cout << "1 0" << "\n";
		}
		else {		
			// 0의 출력횟수는 2번째 자리부터 시작하는 피보나치 수열
			// 1의 출력횟수는 1번째 자리부터 시작하는 피보나치 수열
			cout << fibonacci(tmp - 1) << " " << fibonacci(tmp) << "\n";
		}
	}

	return 0;
}