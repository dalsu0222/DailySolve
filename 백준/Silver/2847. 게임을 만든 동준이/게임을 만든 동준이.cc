#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N;
int result;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N;
	vector<int> Lv(N);
	for (int i = 0; i < N; i++) {
		cin >> Lv[i];
	}

	// 맨 끝 난이도가 가장 높은 난이도여야 최소로 줄이는게 가능하므로,
	// 맨 뒤부터 그 직전 난이도와 비교해가며 직전 난이도를 최소한으로 낮춰가기
	for (int i = N - 1; i > 0; i--) {
		while (Lv[i] <= Lv[i - 1]) {
			result++;
			Lv[i - 1]--;
		}
	}

	cout << result;	// 난이도 낮춘 횟수 출력

	return 0;
}