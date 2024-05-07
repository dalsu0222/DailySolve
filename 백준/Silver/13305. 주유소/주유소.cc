#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
int n;
int cost[100001], dist[100001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> dist[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	long long result = 0;	// 금액 * 거리 를 합한 총 주유비
	long long min_cost = 99999999;	// '과거에 지나온 주유소의 주유비 중 가장 싼 주유비' 저장
	for (int i = 1; i < n; i++) {
		// 과거에 지나온 주유소의 주유비 중 가장 싼 주유비를 선택.
		// 현재 도달한 주유소의 주유비보다 과거에 지나온 주유소의 주유비가 더 싸면, 굳이 현재 주유소에서 주유할 필요가 전혀 없음.
		if (cost[i] < min_cost) {	// 현재 주유비 포함하여 최저 주유비 먼저 갱신 후
			min_cost = cost[i];	
		}
		result += min_cost * dist[i];		// 주유비 계산
	}

	cout << result;

	return 0;
}