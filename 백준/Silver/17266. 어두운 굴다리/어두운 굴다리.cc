#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
int n, m;
int x[100001];

// 실행시간 고려하여 구현 대신 이진탐색으로 접근하기.

int binarySearch() {
	// mid = 가로등의 높이
	int l = 0;
	int r = 100000;
	
	while (l <= r) {
		bool flag = true;
		int mid = (l + r) / 2;
		// 가로등 높이를 총 3구역으로 나누어 탐색한다.
		if (mid < x[0])	// 첫번째 가로등 위치보다 가로등 높이가 부족하다면
			flag = false;
		for (int i = 0; i < m - 1; i++) {
			if (mid * 2 < x[i + 1] - x[i]) {	// (처음과 끝 가로등을 제외한) 가로등 사이사이의 거리보다 가로등 높이가 부족하다면
				flag = false;
				break;
			}
		}
		if (mid < n - x[m - 1])	// 굴다리 끝과 마지막 가로등 위치 차이보다 가로등 높이가 부족하다면 
			flag = false;

		if (flag)		// flag = true 만족하는 경우, 가로등의 높이를 더 줄일 필요가 있다.
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x[i];
	}
	cout << binarySearch();

	return 0;
}