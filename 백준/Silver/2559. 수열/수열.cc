#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> input(n + 1);
	vector<int> sum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
		sum[i] = sum[i - 1] + input[i];	// 구간합 이용하여 시간초과 해결
	}

	int max_t = sum[k];
	for (int i = k + 1; i <= n; i++) {	// k개의 원소로 이루어진 구간
		max_t = max(max_t, sum[i] - sum[i - k]);
	}
	cout << max_t;
	
	return 0;
}