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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int result = 0;	// 짝수로 이루어진 가장 긴 부분 수열의 길이
	int cnt = 0;	// 현재 구간의 홀수 개수
	int l = 0, r = 0;
	while (r < n) {
		if (v[r++] % 2 == 1) {
			cnt++;
		}
		// 홀수 개수가 K를 초과하면 왼쪽 포인터 이동
		while (cnt > k) {
			if (v[l++] % 2 == 1) {
				cnt--;
			}
		}

		// 짝수 부분 수열의 길이 갱신
		result = max(result, r - l - cnt);
	}

	cout << result;

	return 0;
}
