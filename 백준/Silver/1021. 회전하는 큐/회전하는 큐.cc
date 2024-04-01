#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int N, M;
deque<int> dq;
int cnt_2, cnt_3;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	/* 
		1. 1~N 까지 순서대로 저장되어있는 덱(deque) 생성
		2. 뽑고자 하는 원소가 바로 맨 앞에 있는 원소라면, 바로 제거 후 다음 원소찾기 진행
		3. 뽑고자 하는 원소가 덱의 앞/뒤 중에 어디에 가까운지 판별
		4. 덱의 앞과 가깝다면, 2번연산 수행. 뒤와 가깝다면, 3번 연산 수행
		5. 2번연산 수행횟수 + 3번연산 수행횟수 출력
	*/
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {	// 1.
		dq.push_back(i);
	}
	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		int value = dq.front();
		if (value == tmp) {	// 2.
			dq.pop_front();
			continue;
		}

		// 3. 
		int cnt = 0;	// 찾고자 하는 원소 앞에 몇개의 원소가 더 있는지 체크하는 변수
		for (int j = 0; j < dq.size(); j++) {	
			if (dq[j] == tmp)
				break;
			cnt++;
		}
		int mode = 0;	// mode가 0일경우 앞에서부터 시작함을 의미
		if (cnt > dq.size() / 2 || (cnt == dq.size() / 2 && (dq.size()% 2 != 1)) ) {	// 덱의 뒤쪽과 더 가까운 경우, 3번연산을 위한 세팅
			mode = 1;
			cnt = dq.size() - cnt;
		}
		while (cnt > 0) {
			if (mode == 0) {	// 3.
				int tmp2 = dq.front();
				dq.pop_front();
				dq.push_back(tmp2);
				cnt_2++;
			}
			else {	// 4.
				int tmp2 = dq.back();
				dq.pop_back();
				dq.push_front(tmp2);
				cnt_3++;
			}

			cnt--;
		}
		dq.pop_front();		// 1번연산
	}
	cout << cnt_2 + cnt_3; // 5.

	return 0;
}