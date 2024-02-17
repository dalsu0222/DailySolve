#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int L, P, V;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	int index = 1;
	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) {
			break;
		}
		int total = 0;
		total += (V / P) * L;		// L일을 통째로 빌릴 수 있는 횟수(V/P)
		total += min(V % P, L);	// 남은 휴가 중 빌릴 수 있는 나머지 일수, 나머지와 사용가능일 수 중 더 적은일수 선택

		cout << "Case " << index << ": " << total << "\n";
		index++;
	}

	return 0;
}