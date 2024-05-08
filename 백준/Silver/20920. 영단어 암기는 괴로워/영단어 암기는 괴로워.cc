#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
int n, m;
map<string, int> m1;	// (word, cnt)
vector<string> v;	// 단어장

// #20920 : compare 함수를 직접 작성하여 정렬하는 연습 문제

static bool comp(string a, string b) {
	// compare 함수는 가장 까다로운(많은 경우를 만족하는) 조건을 상위에 두고 작성 진행
	if (m1[a] == m1[b] && a.size() == b.size())		// 우선순위 1,2가 동일한경우
		return a < b;		// 우선순위 3으로 판단
	else if (m1[a] == m1[b])		// 우선순위 1이 동일한경우
		return a.size() > b.size();		// 우선순위 2로 판단

	return m1[a] > m1[b];	// 우선순위 1
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.size() < m)		// 길이가 m 이하인경우, 다음 단어 입력받기
			continue;	
		
		if (m1.find(s) != m1.end())	// 단어장에 있는 단어인 경우
			m1[s]++;
		else {	// 단어장에 없는 단어인 경우
			//m1.insert(make_pair(s, 1));
			m1[s] = 1;	// insert 대체
			v.push_back(s);
		}
	}

	sort(v.begin(), v.end(), comp); //compare조건에 따라 정렬

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}