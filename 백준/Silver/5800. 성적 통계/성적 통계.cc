#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int K, N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N;
		vector<int> X(N);
		for (int j = 0; j < N; j++) {
			cin >> X[j];
		}
		sort(X.begin(), X.end());	// 정렬 사용하여 최대, 최솟값 
		int largest_gap = 0;
		for (int j = N - 1; j > 0; j--) {	// 인접한 점수 차이 중 가장 큰 값 갱신
			if (largest_gap < X[j] - X[j - 1])
				largest_gap = X[j] - X[j - 1];
		}
		cout << "Class " << i + 1 << "\n";
		cout << "Max " << X[N - 1] << ", Min " << X[0] << ", Largest gap " << largest_gap << "\n";
	}

	return 0;
}