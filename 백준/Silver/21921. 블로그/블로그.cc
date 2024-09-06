#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, x;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x;
	vector<int> visitor(n);
	vector<int> cumvisitor(n, 0); // 요소를 0으로 초기화
	for (int i = 0; i < n; i++) {
		cin >> visitor[i];
		// O(n^2) 대신 O(n)을 위해 누적 합 이용
		if (i == 0) {
			cumvisitor[i] = visitor[i];
		}
		else {
			cumvisitor[i] = cumvisitor[i - 1] + visitor[i];
		}
	}

	int maxvisit = 0;
	int cnt = 0;
	for (int i = 0; i <= n - x; i++) {
		int xvisit = i == 0 ? cumvisitor[x - 1] : cumvisitor[i + x - 1] - cumvisitor[i - 1];
		if (xvisit > maxvisit) {
			maxvisit = xvisit;
			cnt = 1;
		}
		else if (xvisit == maxvisit) {
			cnt++;
		}
	}
	if (maxvisit) {
		cout << maxvisit << "\n" << cnt;
	}
	else {
		cout << "SAD";
	}

	return 0;
}
