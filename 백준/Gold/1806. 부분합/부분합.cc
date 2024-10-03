#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	vector<int> v(n + 1, 0);	// 누적합 저장
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}
	// 투포인터로 `합이 s 이상인 연속 부분합`들 찾아내기
	int l = 1, r = 1;
	int result = n + 1;
	while (r <= n) {
		while (v[r] - v[l - 1] >= s) {	// 왼쪽 포인터 전진하며 조건을 만족할때까지 계속 최소길이 찾기, 왼쪽 수 버리기
			result = min(result, r - l + 1);
			l++;
		}
		r++;	// 오른쪽 포인터 전진, 오른쪽 방향으로 수 확보
	}
	if (result == n + 1) {
		cout << 0;
	}
	else
		cout << result;

	return 0;
}
