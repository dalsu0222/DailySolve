#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, S, P;

int main(void)
{
	cin >> N >> S >> P;
	vector<long long> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<long long>());	// 내림차순으로 정렬

	int r = 1;		// 등수(rank)
	int cnt = 0;	// 태수의 새로운 점수보다 크거나 같은 점수의 개수
	if (N == 0) {	// 랭킹 리스트가 존재하지 않는 경우, 무조건 1등으로 리스트에 올라감.
		cout << 1;
		return 0;
	}
	else {	// 랭킹 리스트가 존재하는 경우
		// 태수의 새로운 점수에 대한 랭킹(r)과 그보다 크거나 같은 점수의 개수(cnt)를 세준다.
		for (int i = 0; i < N; i++) {
			if (v[i] > S) {
				r++;	
			}
			if (v[i] >= S)
				cnt++;
		}
	}
	if (cnt + 1 > P) {	// 랭킹 리스트에 올라갈 수 없는 경우
		cout << -1;
	}
	else
		cout << r;
	

	return 0;
}