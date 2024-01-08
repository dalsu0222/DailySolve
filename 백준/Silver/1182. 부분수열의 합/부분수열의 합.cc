#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, S;
int arr[20];
bool visited[20];
int sum;
int cnt;

// nx : 현재 만들고 있는 부분 수열의 원소 개수
// x : 원래 수열에서의 순서
void dfs(int nx, int x) {	
	if (sum == S && nx != 0)	// 부분 수열의 합이 S이면서 원소개수가 1 이상인 경우
		cnt++;

	for (int i = 0; i < N; i++) {
		if (!visited[i] && x <= i) {	// 아직 합을 구하지 않은 부분수열만. & 부분 수열 중복 피하기
			visited[i] = true;
			sum += arr[i];
			dfs(nx + 1, i);

			visited[i] = false;	// 백트래킹 설정
			sum -= arr[i];
		}
	}
}

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);
	
	cout << cnt;
		
	return 0;
}
