#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
string s;
string alp[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	int N, B; // 10진법 수 N, B진법
	cin >> N >> B;

	string result = "";

	while (N > 0)
	{
		int r = N % B;
		if (r < 10)
		{
			result += (char)(r + '0');
			// '0'은 ASCII로 48 -> 문자로 변환시켜주려면 int값에 '0'문자를 더해줘야 함
		}
		else
		{
			result += (char)(r - 10 + 'A');
			// 'A'는 ASCII로 65 -> 10을 문자 A로 변환시켜주려면, 숫자 10을 빼고 'A'를 더해주거나, 55를 더해줘야 함
		}

		N /= B; // 다음 연산 진행
	}

	reverse(result.begin(), result.end()); // 문자열 순서 바꿔주기

	cout << result << '\n';

	return 0;
}