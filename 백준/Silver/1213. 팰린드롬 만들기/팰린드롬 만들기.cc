#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	char new_s[51];
	int alp[26] = { 0, };
	for (int i = 0; i < s.size(); i++) {
		char tmp = s[i];
		alp[tmp - 'A']++;
	}
	
	/*
		# 홀수번 등장한 알파벳이 1개 초과일 경우 -> 팰린드롬(회문) 불가
		# 홀수번 등장한 알파벳은 반드시 정답문자열 가운데에 와야함. -> 따로 기억해두기
	*/
	int Odd = 0;
	int mid_i = -1;
	for (int i = 0; i < 26; i++) {
		if (alp[i] <= 0)		// 등장하지 않은 알파벳인경우
			continue;
		if (alp[i] % 2 == 1) {	// 홀수번 등장한 알파벳일때
			Odd++;
			mid_i = i;		// 회문 -> 가운데 자리에 홀수번 등장한 알파벳 두기
			alp[i]--;
		}
	}


	// 가운데를 기준으로, 왼쪽과 오른쪽을 따로 출력
	string ans = "";
	if (Odd > 1)
		cout << "I'm Sorry Hansoo";
	else {
		for (int i = 0; i < 26; i++) {	// i=0~25 : 사전순으로 앞서는대로 출력
			for (int j = 0; j < alp[i] / 2; j++) {
				ans += i + 'A';
			}
		}
		if(Odd)
			ans += mid_i + 'A';
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < alp[i] / 2; j++) {
				ans += i + 'A';
			}
		}
			
	}
	cout << ans;

	return 0;
}