#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000

using namespace std;
int n, m;

long long gcd(long long a, long long b) {	// a < b
	if (b % a == 0) {
		return a;
	}
	return  gcd(b % a, a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<long long> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> m;
	vector<long long> B(m);
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	long long result = 1;
	bool isINF = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			long long gc;
			if (A[i] < B[j])
				gc = gcd(A[i], B[j]);
			else
				gc = gcd(B[j], A[i]);
			
			result *= gc;
			if (result >= INF) {	// overflow시 INF로 나눈 나머지로 바꾸어 저장
				result %= INF;
				isINF = true;
			}
			A[i] /= gc;
			B[j] /= gc;
		}
	}
	if (isINF)
		printf("%09lld", result);	// 9자리 맞춰주기
	else
		cout << result;
	
	return 0;
}
