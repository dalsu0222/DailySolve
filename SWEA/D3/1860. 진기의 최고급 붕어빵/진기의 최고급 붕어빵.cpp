#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int t;
	cin >> t;

	int n, m, k;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		vector<int> arr(n);		// 손님의 도착시간
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());

		bool result = true;
		int max_arr = arr[n - 1];
		int boong = 0;
		int index = 0;
		
		for (int time = 0; time <= max_arr; time++) {
			if (!result)
				break;

			if (time!=0 && time % m == 0) {	// m초마다 k개의 붕어빵을 만듦
				boong += k;
			}
			if (arr[index] == time) {
				if (boong <= 0) {	// 붕어빵 개수가 부족한 경우
					result = false;
					break;
				}
				index++;
				boong--;
			}
			

		}
		if (result)
			cout << "#" << tc << " Possible" << "\n";
		else
			cout << "#" << tc << " Impossible" << "\n";
	}

	return 0;
}