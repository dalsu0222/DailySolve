#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int N;
long long cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	long long h[80001] = { 0, };	// h[i] 범위 고려하여 longlong으로 변경
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	// O(n*n) : 시간초과 -> 스택을 이용하여 O(n)으로 해결
	// i번째까지 나온 건물 높이중에, 스택에 i번째 높이보다 큰 높이만 남겨두면 
	// i번째 높이보다 큰 높이 = i번째 건물을 볼 수 있는 건물의 수가 됨.
	stack <int> s;
	s.push(h[0]);	// 1. 0번째 건물은 스택에 넣어두기
	for (int i = 0; i < N ; i++) {
		while (!s.empty() && s.top() <= h[i]) {	// 2. i번째 건물보다 작거나 같은 건물은 제외
			s.pop();
		}
		cnt += s.size();	// 3. 스택에 남은 건물 수 세주기
		s.push(h[i]);	// 4. 현재 높이를 스택에 추가하여 다음 연산에 반영
	}
	cout << cnt;
	
	return 0;
}