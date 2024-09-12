#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;	// 최소힙
	int temp;
	for (int i = 0; i < n * n; i++) {
		cin >> temp;
		pq.push(temp);
		if (pq.size() > n) pq.pop();	// 사이즈가 n을 넘어가면, 우선순위가 가장 높은 최솟값이 삭제됨
	}
	cout << pq.top();	// top은 n번째로 큰 수가 됨
	
	return 0;
}
