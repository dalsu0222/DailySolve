#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int N, M;
long long nums[100001];		// 시간복잡도 낮추기 위해 dp 배열 사용
int a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		// dp처럼 구간 합을 저장해두기 
		nums[i] = nums[i - 1] + tmp;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		// a번째부터 b번째 수까지의 합 출력
		// (a,b 포함해야하므로 a가 아닌 a-1까지의 합 빼기)
		cout << nums[b] - nums[a - 1] << "\n";
	}
	
	return 0;
}