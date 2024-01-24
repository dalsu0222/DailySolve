#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int T, N;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> stock(N);
		for (int i = 0; i < N; i++) {
			cin >> stock[i];
		}

		long long profit = 0;
		// 그 다음날 오를지 떨어질지 앞에서부터 예측하는 거보다, 뒤에서부터 구하는 것이 더 간결
		int max_v = stock.back();
		for (int i = stock.size() - 2; i >= 0; i--) {
			if (stock[i] > max_v) {
				// 더 큰 값이 등장했다면 max 값을 갱신해주고, 나중에(문제상 전날들) 새로운 max 값과의 차이를 이익화한다.
				max_v = stock[i];
			}
			else {
				// max 값보다 떨어지면 이익을 더해준다.
				profit += (max_v - stock[i]);
			}
		}
		cout << profit << "\n";
	}
	
	return 0;
}