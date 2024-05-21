#include<iostream>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;
	long long cnt = 0;
	while (n % 5) {	// 5로 나눈 나머지가 0이 될때까지 3kg 봉지로 계산
		n -= 3;
		cnt++;
	}
	if (n < 0)	// 4kg, 7kg 과 같이 계산 불가능한 수인 경우
		cout << -1;
	else
		cout << cnt + (n / 5);		// 3kg 봉지개수 + 5kg 봉지개수

	return 0;
}