#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int p, l;
	vector<int> point;
	for (int tc = 0; tc < n; tc++) {
		cin >> p >> l;
		vector<int> score(p);
		for (int i = 0; i < p; i++) {
			cin >> score[i];
		}
		sort(score.begin(), score.end(), greater<int>());		// 내림차순으로 정렬

		if (p < l) {
			point.push_back(1);	// 수강인원 > 신청인원 일 경우, 최소 마일리지 1 로 신청
		}
		else {
			point.push_back(score[l - 1]);		// l 등수의 신청 마일리지와 동일하게 신청
		}
	}

	sort(point.begin(), point.end());	// 신청 포인트 오름차순 정렬
	int cnt = 0;
	// 신청 마일리지가 적은 순대로 카운트 -> 최대 개수로 신청 가능
	for (int i = 0; i < point.size(); i++) {
		if (m >= point[i]) {
			cnt++;
			m -= point[i];
		}
		else
			break;
	}
	cout << cnt;
	
	return 0;
}