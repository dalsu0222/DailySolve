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
	vector<int> doll(n);
	int countRyan = 0;
	for (int i = 0; i < n; i++) {
		cin >> doll[i];
		if (doll[i] == 1) countRyan++;
	}

	if (countRyan < k) {	// 종료조건, 라이언 인형수가 부족한경우
		cout << -1;
		return 0;
	}

	vector<int> cnt(3, 0);
	int l = 0, r = 0;
	int result = n;
	while(r < n) {
		cnt[doll[r++]]++;	// 오른쪽포인터 전진, 오른쪽으로 인형 확보
		while (cnt[1] >= k) {	// k개 이상을 유지할동안 인형 버리기
			result = min(result, r - l);
			cnt[doll[l++]]--;
		}
	}
	cout << result;

	return 0;
}
