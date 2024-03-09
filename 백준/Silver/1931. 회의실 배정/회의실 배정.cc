#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int N;
vector<pair<int, int>> t;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> N;
	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		t.push_back(make_pair(end, start));	// 끝나는 시간 순으로 정렬하기 위해 끝나는 시간을 첫번째 원소로 사용
	}

	sort(t.begin(), t.end());	// 1. 끝나는 시간이 빠른 순으로 정렬

	int cur_time = t[0].first;
	int result = 1;		// 2. 끝나는 시간이 가장 빠른 회의를 가장 먼저 선택한다
	for (int i = 1; i < N; i++) {
		// 3. 끝나는 시간이 빠른 순으로 정렬되어있는 상태에서,
		// 현재 저장되어있는 끝나는 시각보다 동시에or늦게 시작하는 회의를 만나면 최대 개수가 된다
		if (cur_time <= t[i].second) {
			cur_time = t[i].first;
			result++;
		}
	}

	cout << result;

	return 0;
}