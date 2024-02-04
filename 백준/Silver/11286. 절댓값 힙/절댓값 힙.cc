#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ** priority queue의 기본 operator는 내림차순
struct compare {
	bool operator()(int a, int b) {	// operator 함수 override
		if (abs(a) == abs(b))	// 만약 절댓값이 같다면, 작은 값이 우선순위를 가짐
			return a > b;		// a가 b보다 크면(true), 오름차순(음수가 더 앞에), a가 b보다 작으면(false), 내림차순
		else
			return abs(a) > abs(b);	// 절댓값이 작은 순서대로 오름차순으로 정렬
	}
};
int N, x;
priority_queue<int, vector<int>, compare> pq;	// 3번째 인자 default:내림차순

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N;
	while (N--) {
		cin >> x;
		if (x == 0) {	
			if (!pq.size()) {	// 절댓값힙에 저장된 값이 없으면 0 출력
				cout << 0 << "\n";
			}
			else {	// 절댓값이 가장 작은 값 출력하고 절댓값힙에서 제거
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {	
			pq.push(x);
		}
	}

	return 0;
}