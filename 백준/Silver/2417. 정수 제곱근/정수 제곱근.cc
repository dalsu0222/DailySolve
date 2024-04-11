#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
unsigned long long n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n;
	unsigned long long result = (long long)(sqrt(n));	// double 반환값을 longlong으로 변환
	// 부동 소수점 연산의 한계로 인해 정확한 제곱근이 아닌 근사치를 반환할 수 있으므로,
	// 근사치로 나온 result 값 보정
	while (result * result < n)
		result++;
	cout << result;
	/*
	if (sqrt(n) * sqrt(n) == result * result)
		cout << result;
	else
		cout << result + 1;
	*/
	
	return 0;
}