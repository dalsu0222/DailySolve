#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, x;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
	sort(arr.begin(), arr.end());
	/*
		O(n^2) 시간초과 -> 투포인터(O(n)) 이용
	*/
	int cnt = 0;
	int l = 0, r = n - 1;	// 포인터 진행방향 서로 반대
	while(l < r) {
		if (arr[l] + arr[r] < x) {
			l++;
		}
		else if (arr[l] + arr[r] > x) {
			r--;
		}
		else {	// arr[l] + arr[r] == x
			cnt++;
			l++; r--;
		}
	}
	cout << cnt;
	
	return 0;
}