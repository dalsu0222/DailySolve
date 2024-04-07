#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int input[1001];
int box[1001];	// box[i] -> i번째 box에서 담을 수 있는 최대 박스의 개수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	box[1] = 1;
	int max_b = box[1];
	for (int i = 2; i <= n; i++) {
		box[i] = 1;	// 자기 자신(i번째 box)을 담는 경우의수 1으로 초기화
		for (int j = 1; j < i; j++) {	// i번째 box의 이전 box들 검토
			if (input[j] < input[i])	// 상자를 넣을 수 있는 경우라면, 더 많이 넣을 수 있는 경우의 수로 갱신
				box[i] = max(box[i], box[j] + 1);
		}
		if (max_b < box[i])	// 상자를 넣을 수 있는 수중에 최댓값이라면, 최댓값 갱신
			max_b = box[i];
	}
	cout << max_b;
	
	return 0;
}