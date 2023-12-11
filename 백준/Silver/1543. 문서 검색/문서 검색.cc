#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>		// map을 사용하면 M번만 확인하면 되므로 n^2보다 실행시간이 빨라진다.

using namespace std;

string document, word;
int cnt;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	//cin >> document;		// 공백포함한 단어를 입력받아야하므로 getline을 쓰자!!
	//cin >> word;
	getline(cin, document);
	getline(cin, word);

	if (document.length() < word.length()) {	// 찾으려는 단어의 길이가 훨씬 긴 경우 찾지않고종료
		cout << 0;
		return 0;
	}
	else {
		for (int i = 0; i <= document.length() - word.length(); i++) {		// 단어의 첫번째 글자만을 처음에 비교하고 있으므로, 맨 뒤 인덱스에서 단어의 길이만큼 뺀 인덱스 고려
			if (word[0] == document[i]) {	// 첫글자와 일치할경우 단어 검사 
				string tmp = document.substr(i, word.length());	// 찾고자 하는 단어 길이만큼 잘라서 일치하는지 비교
				if (tmp == word) {
					cnt++;
					i += word.length() - 1;	// for문에서 바로 i가 1 증가되므로, -1 을 첨가하여 계산
					// 단어길이만큼 인덱스 뒤로 밀기!
				}
			}
		}
	}
	cout << cnt;

	return 0;
}