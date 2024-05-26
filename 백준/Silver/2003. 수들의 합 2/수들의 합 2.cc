#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	/*
		시간 제한 0.5초 -> O(n)으로 풀기위해 투포인터 사용
	*/

	int A[10001] = { 0, };
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	int l = 1, r = 1;	// l = left, r = right
	int total = A[1];
	int cnt = 0;
	while (l <= n && r <= n) {
		if (total < m) {
			r++;
			if (r <= n)	// 범위 이내인 경우만 연산
				total += A[r];
		}
		else if (total > m) {
			total -= A[l];
			l++;
		}
		else {	// total == m
			total -= A[l];
			cnt++;
			l++;	r++;	// 기존 l과 r 위치에서는 더이상 합이 m일수가 없음. [l,r+1], [l+1,r] 구간 전부 불가능.
			if (r <= n)	// 범위 이내인 경우만 연산
				total += A[r];
		}
	}
	cout << cnt;
	
	
	return 0;
}