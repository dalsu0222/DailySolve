#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> A;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (A.empty() || A.back() < tmp) {	// A가 비어있거나(i=0) 이전보다 더 큰 수가 입력되는 경우
			A.push_back(tmp);
		}
		else {		// 더 작은수가 입력되는 경우 
			// lower_bound => target값보다 같거나 큰(이상인) 첫번째 위치 iterator 반환
			*lower_bound(A.begin(), A.end(), tmp) = tmp;	// 해당 위치 iterator 값 참조하여 해당값으로 대체
			// 원리:기존에 있던 값보다 더 작은값으로 갱신하여 증가하는 부분 수열을 더 길게 만들기 위함
		}
	}	

	cout << A.size();

	return 0;
}