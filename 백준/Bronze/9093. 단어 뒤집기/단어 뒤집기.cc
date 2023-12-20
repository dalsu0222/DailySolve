#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int T;
string s;
stack <char> st;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	cin.ignore();		// 입력 버퍼 지워주기
						// (cin 사용 후에, 여전히 \n가 입력버퍼에 남아있어서 getline에서 '\n가 s로 입력이 된다.)
	for (int i = 0; i < T; i++) {
		getline(cin, s);	
		s += ' ';	// 공백 기준으로 단어를 출력하기 위해 마지막 단어에도 ' ' 붙여주기

		for (int j = 0; j < s.length(); j++) {
			if (s[j] == ' ') {		// 하나의 단어가 끝났다면
				while (!st.empty()) {		// 단어 거꾸로 출력(스택 구조에 따라 최근저장이 먼저 출력)
					cout << st.top();
					st.pop();		// stack 에서 꺼내서 출력할때는, top() -> pop() 이용
				}
				cout << ' ';
			}
			else
				st.push(s[j]);
		}
		cout << "\n";
	}

    return 0;
}
