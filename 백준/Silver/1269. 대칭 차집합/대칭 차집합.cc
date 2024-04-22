#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int n, m;
int cnt;
map<int, bool> set;	// key, value

int main(void)
{
	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n + m; i++) {
		cin >> tmp;
		if (set[tmp] == true)	// 이미 true로 존재하는 key라면(이미 등장했던 수라면)
			set.erase(tmp);	// 합집합에서 지우기
		else
			set[tmp] = true;	// 존재하지 않는 수가 들어온거라면, 합집합에 추가하기
	}

	cout << set.size();
	
	return 0;
}