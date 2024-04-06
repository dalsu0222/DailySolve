#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int N;

int star(int i, int j, int n) {	// 재귀
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)	// 빈칸일 경우 바로 출력(n/3해도 검사해도 동일)
		cout << " ";
	else if (n / 3 == 0)	// 위의 조건을 만족하지 않는경우, * 으로 둘러싸기
		cout << "*";
	else  // 빈칸이 아닌경우 재귀적으로(n/3) 반복해 빈칸 검사
		star(i, j, n / 3);
	
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star(i, j, N);
		}
		cout << "\n";
	}

	return 0;
}