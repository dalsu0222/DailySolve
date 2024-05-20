#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// N <= 10^5 이므로, 단순히 완탐으로 풀기엔 시간 오래걸림.

	cin >> s;
	sort(s.begin(), s.end(), greater<int>());	// 가장 큰 수가 되도록 내림차순으로 정렬
	/*
		30의 배수가 되는 조건
		1. 일의자리가 0으로 끝날것
		2. 30은 3의 배수이므로 각 자리의 합이 3의 배수어야 할 것
	*/
	
	if (s[s.size() - 1] != '0') {
		cout << -1;
	}
	else {
		long long total = 0;
		for (int i = 0; i < s.size(); i++) {
			total += s[i] - '0';
		}
		if (total % 3 == 0)
			cout << s;
		else
			cout << -1;
	}


	return 0;
}