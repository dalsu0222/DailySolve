#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;
int day;

int main(void)
{
	cin >> n;
	vector<int> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	sort(t.begin(), t.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		t[i]++; // 묘묙 심는데 1일 소모
		t[i] -= (n - i);	// 남은 시간동안 자란 만큼 일수 빼주기
	}
	sort(t.begin(), t.end(), greater<int>());	// 다 심고나서 남은 일 수 중 가장 큰것 구해주기
	cout << n + t[0] + 1;	// (심는데 소요된 시간 + 다심고나서도 남은 시간 중 max값 + 1일(그 다음날 초대하므로) ) 출력

	return 0;
}