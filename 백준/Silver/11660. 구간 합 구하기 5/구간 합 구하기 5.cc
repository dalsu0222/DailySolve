#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
int N, M;
long long nums[1025][1025];	// dp[i][j] : (1,1) 부터 (i,j) 까지의 합(직사각형 모양의 영역)

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int tmp;
	for (int i = 1; i <= N; i++) {
		long long sum = 0;
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			// 간접적으로 nums[i][j] 구해주기, 중복되는 영역은 반드시 제외
			nums[i][j] = nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1] + tmp;
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		// nums[i][j] 구할때와 같은 원리 적용, 2번 제외되는 영역은 다시 추가
		long long result = nums[x2][y2] - nums[x1 - 1][y2] - nums[x2][y1 - 1] + nums[x1 - 1][y1 - 1];
		cout << result << "\n";
	}
	

	return 0;
}