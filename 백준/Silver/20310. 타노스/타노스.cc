#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int cnt_0, cnt_1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			cnt_0++;
		else
			cnt_1++;
	}
	cnt_0 /= 2;		cnt_1 /= 2;
	// 사전순으로 가장 빠른것을 구하기 위해, 
	// 0은 뒤에서부터, 1은 앞에서부터 절반개수씩 삭제 진행
	bool isdeleted[501] = { false, };
	for (int i = s.size() - 1; i >= 0; i--) {	
		if (s[i] == '0' && cnt_0 > 0) {
			isdeleted[i] = true;
			cnt_0--;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1' && cnt_1 > 0) {
			isdeleted[i] = true;
			cnt_1--;
		}
	}
	
	// 출력
	for (int i = 0; i < s.size(); i++) {
		if (!isdeleted[i])
			cout << s[i];
	}
	
	return 0;
}