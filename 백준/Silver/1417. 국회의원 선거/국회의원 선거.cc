#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<pair<int,int>> v(n); // { 득표수, 후보자번호 }
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v[i] = { tmp,i };
	}
	if (n == 1) {	// 후보자가 다솜 1명일경우, 0
		cout << "0";
		return 0;
	}
	while (1) {
		sort(v.begin(), v.end(), greater<>());	// 표 순 기준으로 내림차순 정렬
		if (v[0].second == 0 && v[1].first != v[0].first) {	// 최다득표자가 다솜이고, 동점자가 없다면 -> 출력 후 종료
			cout << result;
			break;
		}

		int dasomIndex = 0;
		for (int i = 0; i < n; i++) {	// 다솜이의 위치(인덱스) 찾기
			if (v[i].second == 0) {
				dasomIndex = i;
				break;
			}
				
		}
		// 최다득표자의 득표수 뺏어오기
		result++;	
		v[0].first--;
		v[dasomIndex].first++;
	}

	return 0;
}