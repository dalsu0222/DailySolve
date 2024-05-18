#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	int n, m;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m;
		vector<int> r(n + 1);
		for (int i = 1; i <= n; i++) {	// 단위 무게당 요금 입력받기
			cin >> r[i];
		}

		map<int, int> w;		// 차량번호, 요금 key-value pair
		int tmp;
		for (int i = 0; i < m; i++) {	// 차량의 무게 입력받기
			cin >> tmp;
			w.insert(make_pair(i + 1, tmp));
		}
		int total = 0;
		vector<bool> enter(n + 1);		// 주차 자리 비어있는지 여부
		vector<int> seat(n + 1);		// 주차된 차량 번호 저장
		int num;	// 차량번호
		queue<int> waitnum;	// 차량 대기열
		int index = 0;
		for (int i = 0; i < m * 2; i++) {
			cin >> num;
			bool isEnter = false;
			if (num > 0) {	// 차량이 들어오는 경우
				for (int j = 1; j <= n; j++) {
					if (!enter[j]) {
						enter[j] = true;	// j번째 자리에 주차
						seat[j] = num;	// j번째 자리에 num 차량 주차
						total += r[j] * w[num];	// 주차 비용 계산
						isEnter = true;	// 주차 성공
						break;
					}
				}
				if (!isEnter) {	// 꽉차서 주차를 성공하지 못한경우
					waitnum.push(num);		// 대기열에 추가
				}
			}
			else {		// 차량이 나가는 경우
				num = -num;
				for (int j = 1; j <= n; j++) {
					if (seat[j] == num) {
						enter[j] = false;	
						// 대기하고 있는 차량이 있으면 넣기
						if (!waitnum.empty()) {
							int nnum = waitnum.front();
							waitnum.pop();
							seat[j] = nnum;
							enter[j] = true;
							total += r[j] * w[nnum];
						}
						break;
					}
				}
			}
		}
		
		cout << "#" << tc << " " << total << "\n";

		
	}
	
	return 0;
}