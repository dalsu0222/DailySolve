#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int A[1000001];
int dp[1000001];		// dp[a]=b 는 'a번째 값이 가지는 가장 긴 증가하는 부분수열의 길이는 b'를 의미

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	dp[1] = 1;
	int max_l = 1;		// 최소 길이는 1이다. (0했을시 틀림) 전부 감소하는 경우 맨 앞수만 길이로 쳐준다.
	
	for (int i = 2; i <= N; i++) {
		dp[i] = 1;		// 초기화
		for (int j = i - 1; j >= 1; j--) {	// 이전까지의 등장한 수들중 현재(i)보다 더 작은 수 중에 가장 긴 부분수열 길이+1 = 현재 최대 길이
			if (A[j] < A[i]) {	// 작은 수들 중 길이가 가장 큰 값 찾아 1 더하기
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (max_l < dp[i]) {		// 더 큰 길이가 있다면 갱신
			max_l = dp[i];
		}
	}
	cout << max_l << "\n";
	// --------- 기존 코드 활용 -----------

	vector <int> result;
	for (int i = N; i > 0; i--) {
		// 뒤에서부터 최대길이에 맞는게 있으면 정답에 넣고 그 길이로부터 1씩 제거하면서 파악
		if (dp[i] == max_l) {
			result.push_back(A[i]);
			max_l--;
		}
	}
	// 뒤에서부터 넣었으므로 내림차순 상태, 오름차순 출력위해 뒤에서부터 출력
	for (int i = result.size()-1; i >= 0; i--) {
		cout << result[i] << " ";
	}

	return 0;
}