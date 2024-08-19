#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long n, m;
vector<long long> budget;

// 상한액으로 모든 요청을 배정할 수 있는지의 여부를 반환하는 함수 
bool isRequestedEnough(long long num) {
	long long total = 0;
	for (int i = 0; i < n; i++) {
		if (budget[i] >= num) {
			total += num;
		}
		else {
			total += budget[i];
		}
	}
	return m >= total ? true : false;
}

// 이분 탐색을 이용하여, 최대상한액을 찾는 함수
long long maxBudget() {
	long long start = 1;
	long long end = *max_element(budget.begin(), budget.end());
	while (start <= end) {
		long long mid = (start + end) / 2; // mid : 상한액
		if (isRequestedEnough(mid)) {	// 모든 요청을 배정할 수 있는 경우, 상한액 늘리기
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return end;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	long long tmp; // int도 가능할듯
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		budget.push_back(tmp);
	}
	cin >> m;

	cout << maxBudget();
	

	return 0;
}
