#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
int N;
char T;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T;
	string s;
	map<string, int> p;
	for (int i = 0; i < N; i++) {
		cin >> s;
		
		if (p.find(s) != p.end()) {	// map에서 데이터를 찾았을 때
			p.find(s)->second++;
		}
		else {	// 입력받은 이름이 map에서 존재하지 않을때
			p.insert(make_pair(s, 1));
		}
	}

	if (T == 'Y') {	// 'Y' 게임(2인용)인 경우, 인원수만큼 게임을 진행하면 됨.
		cout << p.size();
	}
	// Y 이외의 게임은, 임스 제외 필요한 인원수 만큼 게임을 진행
	else if (T == 'F') {	
		cout << p.size() / 2;
	}
	else {
		cout << p.size() / 3;
	}

	return 0;
}