#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> nums;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());		// default : 오름차순 정렬

	for (int i = 0; i < N; i++)
		cout << nums[i] << "\n";

	return 0;
}