#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	string s;
	cin >> s;

	vector<string> v;
	for (int i = 0; i < s.size(); i++) {
		string tmp = s;
		tmp.erase(0, i);	// 0번째 인덱스부터 i개만큼 글자 삭제
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());	// 오름차순 정렬(알파벳순)
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	
	return 0;
}