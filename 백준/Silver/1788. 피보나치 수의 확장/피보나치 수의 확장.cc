#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int fibo[1000001] = { 0,1, };
int mfibo[1000001] = { 0,1,-1};
int n, result;

int fibonacci(int n) {
	if (n == 0 || n == 1)
		return fibo[n];
	else if (fibo[n] == 0) {
		fibo[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 1000000000;
	}
	return fibo[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	// 음수 피보나치 규칙성 : 양수 피보나치일때와 값은 대칭이되, 절댓값이 짝수일때 - 부호를 가짐
	if (n >= 0) {
		result = fibonacci(n);
	}
	else {	// n<0일때, 규칙성을 바탕으로 값 구해주기
		if (-n % 2 == 0)
			result = -fibonacci(-n);
		else
			result = fibonacci(-n);
	}
	
	if (result > 0)
		cout << 1 << "\n" << result;
	else if(result == 0)
		cout << 0 << "\n" << result;
	else
		cout << -1 << "\n" << abs(result);
	
	return 0;
}