#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int N;
vector<int> arr;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	deque<int> dq;		// 카드를 앞 뒤로 넣어야 하므로 deque 사용
	for (int i = 1; i <= N; i++) {
		if (arr[N - i] == 1) {	// 기술 순서를 역순으로 계산하여 최종 상태 맞추기
			dq.push_front(i);
		}
		else if (arr[N - i] == 2) {
			int tmp = dq.front();	// 앞에서 2번째 자리에 삽입
			dq.pop_front();
			dq.push_front(i);
			dq.push_front(tmp);
		}
		else if (arr[N - i] == 3) {
			dq.push_back(i);
		}
	}
	for (int i = 0; i < N; i++) {	// 앞에서부터 차례대로 출력
		cout << dq[i] << ' ';
	}

	return 0;
}