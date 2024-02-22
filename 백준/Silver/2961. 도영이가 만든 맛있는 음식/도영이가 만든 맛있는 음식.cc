#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
pair<int, int> input[10];
pair<int, int> output[10];		// 모든 경우의 수 저장
int result = 9999999;

void calc(int index, int cnt) {
	if (cnt > 0) {
		int S = output[0].first;
		int B = output[0].second;
		for (int i = 1; i < cnt; i++) {		
			S *= output[i].first;
			B += output[i].second;
		}
		result = min(result, abs(S - B));
	}
	if (cnt == N)
		return;

	for (int i = index; i < N; i++) {
		output[cnt] = make_pair(input[i].first, input[i].second);
		calc(i + 1, cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

    cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i].first >> input[i].second;
	}
	
	calc(0, 0);
	cout << result;

	return 0;
}