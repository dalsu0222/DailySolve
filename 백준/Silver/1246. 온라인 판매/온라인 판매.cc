#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;

int main() {
	cin >> n >> m;
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	long long max_total = 0;
	int min_p = 0;
	int k = min(n, m);
	for (int i = 1; i <= k; i++) {	// 최대 이익을 위해, 가장 높은 금액부터 팔기
		int total = p[m- i] * i; // 뒤에서부터 i개씩 p[m-i] 가격으로 팔기
		if (max_total < total) {
			max_total = total;
			min_p = p[m - i];
		}
	}
	cout << min_p << " " << max_total;
	
	return 0;
}