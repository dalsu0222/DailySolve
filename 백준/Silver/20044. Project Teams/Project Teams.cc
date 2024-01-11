#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
vector<int> arr;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int tmp;
	for (int i = 0; i < 2 * n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	// 학생들의 코딩역량 정렬
	sort(arr.begin(), arr.end());

	// 최솟값(result) 초기 설정, 가장 코딩역량이 작은 학생과 큰 학생을 매치시킨다.
	int result = arr[0] + arr[2 * n - 1];

	// 그 이후 코딩역량이 i번째로 작은 학생과 i번째로 큰 학생을 조합한다.(앞에서 i번째, 뒤에서 i번째)
	for (int i = 1; i < 2 * n; i++) {
		// 둘의 합이 최소가 되는 결과를 찾아나간다.
		result = min(result, arr[i] + arr[2 * n - i - 1]);
	}

	cout << result;

	return 0;
}
