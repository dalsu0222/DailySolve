#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int t, n;

int main(void)
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		// 난이도가 최소가 되도록 배치하고자 한다면,
		// 어떤 한 수를 기준으로, 정렬 후에 차이가 가장 적게 나는 것을 양옆에 배치하게 된다.
		// 따라서, 정렬 후 현재 위치에서 2칸 떨어진 곳의 수의 차이 중 최대값을 고르면 된다.
		int result = v[1] - v[0];	// 첫 값과 끝 값은 연결되어 있으므로 차이 미리 저장
		for (int i = 2; i < n; i++) {
			result = max(result, v[i] - v[i - 2]);
		}

		cout << result << "\n";
	}
	
	return 0;
}