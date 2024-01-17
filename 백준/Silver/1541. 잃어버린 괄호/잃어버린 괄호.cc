#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string s;
int total;

bool isplusminus(char x) {
	if (x == '+' || x == '-')
		return true;
	return false;
}

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	
	string number;	// 피연산자를 저장할 string 변수
	int sign = 1;	// 처음에 들어오는 수는 무조건 양수라고 가정, 부호 +로 초기화
	bool isminus = false;		// 앞에서 마이너스부호가 등장했는지 저장하는 변수
	for (int i = 0; i < s.size(); i++) {
		if (!isplusminus(s[i])) {	// 피연산자인경우 string 변수에 저장
			number += s[i];
		}
		if (i == s.size() - 1 || isplusminus(s[i])) {	// 인덱스 맨마지막이거나 연산자인 경우
			int op = stoi(number);	// 피연산자를 int형으로 변환
			total += sign * op;		// 부호와 곱하여 식의 값 계산
			number = "";	// 피연산자 초기화
			if (s[i] == '-') {	// 마이너스 부호가 등장했다면,
				sign = -1;		// 그 다음 피연산자의 연산을 위해 부호 - 로 설정
				isminus = true;
			}
			else {
				if (isminus)	// 앞에서 - 부호가 등장했다면 그 뒤의 연산도 -로 진행(괄호 적용!)
					sign = -1;
				else
					sign = 1;
			}

		}
	}

	cout << total;

	return 0;
}
