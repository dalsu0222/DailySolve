#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000

using namespace std;
int n;
int primeArr[MAX] = { 0 };

void primeChk() {	// 가능한 소수를 미리 구해두기, 에라토스테네스의 체 이용
	for (int i = 2; i * i <= MAX; i++) {
		if (primeArr[i] == 0) {
			for (int j = i * i; j <= MAX; j += i) {
				primeArr[j] = 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp;
	primeChk();	// 가능한 소수를 모두 미리 구해두기
	while(true) {
		cin >> tmp;
		if (tmp == 0) {	// 종료조건
			break;
		}

		bool isConjecture = false;
		// b-a가 가장 큰 것을 출력
		// 6 <= tmp < 1000000 이므로, i=3부터 시작. 또한 소수일려면 일단 홀수여야하므로 i+=2씩 진행.
		for (int i = 3; i <= tmp; i+=2) {
			int a = i;
			int b = tmp - i;
			if (primeArr[a] == 0 && primeArr[b] == 0) {	// a,b 둘다 소수이면, 동시에 b-a가 가장 큰 소수 쌍이 됨.
				cout << tmp << " = " << a << " + " << b << "\n";
				isConjecture = true;
				break;
			}
		}
		if (!isConjecture)
			cout << "Goldbach's conjecture is wrong." << "\n";
	}
	
	return 0;
}
