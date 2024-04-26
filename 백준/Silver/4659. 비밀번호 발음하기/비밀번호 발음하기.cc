#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string input;

bool isvowel(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		return true;
	return false;
}

int main(void)
{
	cin >> input;
	while (input != "end") {
		// 조건 1 검사
		int vowel = 0;
		for (int i = 0; i < input.size(); i++) {
			char tmp = input[i];
			if (isvowel(tmp))
				vowel++;
		}
		// 조건 2 검사
		bool cnt1 = false, cnt2 = false;
		if (input.size() >= 3) {	// 길이가 3 이상인지 체크하여 out of range 방지
			for (int i = 0; i < input.size() - 2; i++) {
				// 모음이 3개 연속으로 오는 경우
				if (isvowel(input[i]) && isvowel(input[i + 1]) && isvowel(input[i + 2])) {
					cnt1 = true;
				}
				// 자음이 3개 연속으로 오는 경우
				if (!isvowel(input[i]) && !isvowel(input[i + 1]) && !isvowel(input[i + 2])) {
					cnt2 = true;
				}
			}
		}
		// 조건 3 검사
		bool iscontinue = false;
		for (int i = 0; i < input.size() - 1; i++) {
			char tmp1 = input[i];
			char tmp2 = input[i + 1];
			if (tmp1 == 'e' && tmp2 == 'e' || tmp1 == 'o' && tmp2 == 'o')
				continue;
			if (tmp1 == tmp2)
				iscontinue = true;
		}


		if (vowel && !cnt1 && !cnt2 && !iscontinue)
			cout << "<" << input << ">" << " is acceptable.\n";
		else
			cout << "<" << input << ">" << " is not acceptable.\n";

		cin >> input;
	}
	
	return 0;
}