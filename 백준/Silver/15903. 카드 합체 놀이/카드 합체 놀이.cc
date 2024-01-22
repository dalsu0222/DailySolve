#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n, m;
// 정렬의 번거로움을 줄이기 위해 우선순위 큐 사용
// priority_queue<T, Container<T>, Compare> pq;
// T = 저장할 데이터 type, Container<T> : 벡터와 같은 컨테이너 타입, Compare는 비교함수(default는 less<T>)
priority_queue<long long, vector<long long>, greater<long long>> pq;
long long total;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	// m번 진행할때마다 카드 오름차순 정렬
	// 가장 수가 작은 카드(맨 앞 2개) 고르면 가장 작은 점수 선택 가능
	// "정렬 -> 맨앞카드 2개 선택 후 새로운 값으로 치환"을 m번 반복
	for (int i = 0; i < m; i++) {
		long long sum = 0;
		for (int j = 0; j < 2; j++) {		// 제일 작은 수 2개 뽑아 더하기
			sum += pq.top();
			pq.pop();
		}
		for (int j = 0; j < 2; j++) {	// 만들어진 수로 기존 수 덮어쓰기
			pq.push(sum);
		}
	}

	// 우선순위 큐(pq)에는 결과 배열이 들어있음
	while (!pq.empty()) {
		total += pq.top();
		pq.pop();
	}

	cout << total;

	return 0;
}