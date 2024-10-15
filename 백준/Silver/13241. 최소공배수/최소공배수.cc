#include <iostream>

using namespace std;
long long a, b;

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	cout << a * b / gcd(a, b);	// 두수의 곱 / 최대공약수 = 최소공배수

	return 0;
}
