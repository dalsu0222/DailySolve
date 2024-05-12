#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
int n;
int input[1000001];
int nge[1000001];
stack<int> s;		// 스택에 들어가는 수 : 아직 오큰수를 구하지 못했거나 오큰수가 없는 위치(인덱스)

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < n; i++) {
		// 현재 위치의 값이 더 크면, 스택의 top에 해당하는 위치의 오큰수가 됨.
		while (!s.empty() && input[s.top()] < input[i]) {	
			nge[s.top()] = input[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {	// 스택에 남아있는 위치(인덱스)는 오큰수가 없는 위치
		nge[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << nge[i] << " ";
	}

	return 0;
}