#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	vector<int> p(n), cost(n-1);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n - 1; i++) {	// 키차이 저장
		cost[i] = p[i + 1] - p[i];
	}
	sort(cost.begin(), cost.end());
	int result = 0;
	for (int i = 0; i < n - k; i++) {	// 키차이가 큰 k개를 구분선(각 그룹에 미리 포함)으로 사용
		result += cost[i];	// 0 ~ n-k-1까지, 남은 키 차이만 비용으로 계산
	}

	cout << result;
	
	return 0;
}
