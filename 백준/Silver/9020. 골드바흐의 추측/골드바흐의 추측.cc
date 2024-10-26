#include <iostream>

using namespace std;
int n;

// 소수인지 여부를 판별하는 함수
bool isPrime(int x) {
	if (x < 2) return false;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;

		// 두 소수의 차이가 가장 작은 것을 출력
		int a = tmp / 2;
		int b = tmp / 2;
		while (1) {
			if (isPrime(a) && isPrime(b)) {
				cout << a << " " << b << "\n";
				break;
			}
			a -= 1;	// 차이를 1씩 벌려가며 두 수가 전부 소수인지 확인
			b += 1;
		}
	}

	
	return 0;
}
