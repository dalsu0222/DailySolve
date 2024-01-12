#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
string s;
int zeroarea;
int onearea;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	int result = 0;	// 행동의 최소횟수
	for (int i = 0; i < s.length(); i++) {
		/*	i = s.length()-1 일때,
			 s[i + 1]의 값이 '\0' (문자열의 끝을 나타내는 널 문자)로 간주되어 비교되므로,
			 따라서 아래 if문의 조건이 거짓이 된다. 
		*/
		if (s[i] != s[i + 1]) {	// 값이 바뀌는 지점에서만 영역 카운트
			if (s[i] == '0')
				zeroarea++;
			else
				onearea++;
		}
	}

	// 0의 영역과 1의 영역 중 더 작은 영역에 해당하는 횟수를 출력
	cout << min(zeroarea, onearea);	

	return 0;
}
