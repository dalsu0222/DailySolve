#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int N;
string word;
int cnt;	// 그룹 단어가 아닌 갯수

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		bool alphabet[26] = { false, };	// 알파벳 출현유무 저장하는 배열, 단어 들어올때마다 초기화
		alphabet[word[0] - 'a'] = true;

		for (int j = 1; j < word.length(); j++) {
			// 같은 문자의 연속인경우
			if (word[j] == word[j - 1]) {
				continue;
			}
			// 연속하지 않고, 이미 나왔던 문자라면 그룹단어가 아닌 갯수 카운트 1 증가
			else if (word[j] != word[j - 1] && alphabet[word[j] - 'a'] == true) {
				cnt++;
				break;
			}
			// 처음 나오는 문자라면
			else {
				alphabet[word[j] - 'a'] = true;
			}
		}
	}
	
	cout << N - cnt;	// 그룹 단어가 아닌 경우 제외하여 계산, 출력

    return 0;
}
