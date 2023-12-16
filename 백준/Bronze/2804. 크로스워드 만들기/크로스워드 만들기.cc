#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	//겹치는 y, x 찾기
	int y = 0, x = 0;
	for (int i = 0; i < a.length(); i++){
		bool search = true;
		for (int j = 0; j < b.length(); j++)
			if (a[i] == b[j]){	// 겹치는 x,y 찾아서 갱신
				y = i;
				x = j;
				search = false;
				break;
			}
		if (!search)		// 찾은게 있다면 바로 종료(첫번째값 출력하기 위함)
			break;
	}

	for (int i = 0; i < b.length(); i++){
		for (int j = 0; j < a.length(); j++) {
			if (j == y && i != x)
				cout << b[i];
			else if (i == x)
				cout << a[j];
			else
				cout << ".";
		}
		cout << "\n";
	}

	return 0;
}