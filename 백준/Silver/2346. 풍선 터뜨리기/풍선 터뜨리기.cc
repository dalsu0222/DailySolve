#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int N;
deque<pair<int,int>> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	/* 
	1. 풍선에 적혀있는 수와 순서를 pair(쌍)으로 덱에 차례대로 넣기
	2. 덱의 맨 앞 원소에 해당하는 순서 출력
	3. 덱의 맨 앞 원소 = 해당 회차에 이동할 거리 임을 이용하여 양수,음수에 따라 이동
	4. 번호만큼 앞뒤로 이동할때, 터뜨릴 풍선 번호가 >>항상 덱의 맨 앞에 위치하도록<< 이동
	*/
	
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		dq.push_back(make_pair(tmp,i+1));	// 1. 
	}

	for (int i = 0; i < N; i++) {
		int cnt = dq.front().first;	// 3.
		cout << dq.front().second << " ";	// 2.
		dq.pop_front();

		if (i == N - 1)	// 마지막 하나의 원소만 남았을 경우, 종료
			break;

		// 3.
		if (cnt > 0) {	// 양수가 적혀있는경우, 오른쪽으로 이동
			for (int j = 1; j < cnt; j++) {	// 4. cnt가 양수이면 이미 출력후 pop을 한번 했기에 cnt-1번만 이동
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {	// 음수가 적혀있는경우, 왼쪽으로 이동
			for (int j = 0; j < -cnt; j++) {		// 4.
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		
	}

	return 0;
}