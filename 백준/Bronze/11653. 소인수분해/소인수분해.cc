#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int N;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	if (N == 1) return 0;

	for (int i = 2; i <= N; i++) {
		while (N % i == 0) {		// i=2부터 시작하여 나누어떨어지는경우(약수이자 소수) 계속 나누기
			cout << i << "\n";
			N /= i;
		}
	}

    return 0;
}
