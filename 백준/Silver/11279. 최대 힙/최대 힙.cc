#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, x;
priority_queue<int, vector<int>> pq;	// 3번째 인자 default:내림차순

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N;
	while (N--) {
		cin >> x;
		if (x == 0) {	
			if (!pq.size()) {	// 최대힙에 저장된 값이 없으면 0 출력
				cout << 0 << "\n";
			}
			else {	// 최댓값 출력하고 최대힙에서 제거
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {	// 0 제외 수 입력받으면, 최대 힙에 수 x 추가
			pq.push(x);
		}
	}

	return 0;
}