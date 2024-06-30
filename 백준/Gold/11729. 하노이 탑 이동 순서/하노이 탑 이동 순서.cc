#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
/*
하노이탑 알고리즘
1. n-1개의 원판을 3번 장대를 거쳐 2번 장대로 옮긴다.
2. 1번 장대에 있는 가장 큰 크기의 원판을 3번 장대로 옮긴다.
3. 2번 장대에 있는 n-1개의 원판을 1번 장대를 거쳐 3번 장대로 옮긴다.
*/
void hanoi(int n, int start, int to, int via) {
	if (n == 1)
		cout << start << " " << to << "\n";
	else {
		hanoi(n - 1, start, via, to);	// 1.
		cout << start << " " << to << "\n";	// 2. move
		hanoi(n - 1, via, to, start);	// 3.
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << (int)pow(2, n) - 1 << "\n";	// pow 대신 시프트 연산 1 << n 사용 가능
	hanoi(n, 1, 3, 2);

	return 0;
}