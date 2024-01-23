#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// n,m 제외 자료형 전부 long long int 로 변경
using namespace std;
int m, n;
long long result;		// 값 초과 방지를 위해 long long int로 변경
vector<int> prime;

bool isprime(int x) {	// x의 제곱근까지만 연산
	if (x == 1)		// x=1이면 소수가 아니라는 조건 추가
		return false;

	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)	// 약수가 존재하면 소수가 아님
			return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (isprime(i)) {
			prime.push_back(i);
			result += i;
		}
	}
	
	if (!prime.empty()) {
		cout << result << "\n";
		cout << prime[0];		// m~n 사이 소수중에, 가장먼저 저장된 소수가 가장 작은 소수
	}
	else {
		cout << "-1";
	}
	
	return 0;
}