#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int dump;	// 덤프 횟수	
	for (int tc = 1; tc <= 10; tc++) {
		cin >> dump;
		vector<int> h(100);
		for (int i = 0; i < 100; i++) {
			cin >> h[i];
		}

		int result = 0;
		sort(h.begin(), h.end());
		for (int i = 0; i < dump; i++) {
			int d = h[99] - h[0];
			if (d <= 1) {
				//result = d;
				break;
			}
			h[99]--;		// 덤프
			h[0]++;
			sort(h.begin(), h.end());	// 덤프 후 재정렬
		}
		result = h[99] - h[0];		// 덤프 종료 후 높이 차 반환

		cout << "#" << tc << " " << result << "\n";
	}
	
	return 0;
}