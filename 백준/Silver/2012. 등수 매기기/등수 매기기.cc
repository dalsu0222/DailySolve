#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> r;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		// n명의 예상 등수 입력받기
		int tmp;
		cin >> tmp;
		r.push_back(tmp);
	}
	sort(r.begin(), r.end());	// 등수를 오름차순으로 정렬
	
	long long total = 0;		// 크기 고려하여 long long으로 선언해주기
	for (int i = 0; i < N; i++) {	
		// 정렬한 뒤 정직한 오름차순 등수와의 차이를 계산하면 불만도의 합 최소가 됨.
		// 예제 : r = { 1,1,2,3,5} 일때, 불만도는 각각 {0,1,1,1,0}
		total += abs(i + 1 - r[i]);
	}

	cout << total;

	return 0;
}
