#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int N;
char cookie[1001][1001];
int x, y;
int la, ra, w, ll, rl;

int main(void)
{
	/* 
		key point
		1. 처음 등장하는 '*'의 위치가 바로 머리의 위치.
		2. 머리의 위치를 기준으로 나머지 부위들의 길이도 상대적으로 측정 가능
	*/
	cin >> N;
	bool ishead = false;	// 머리 등장여부 저장
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cookie[i][j];
			if (!ishead && cookie[i][j] == '*') {	// 머리가 아직 등장하지 않은 상태라면
				ishead = true;	
				x = i;	y = j;	// 머리 위치 저장
			}
		}
	}

	// (x,y) : 머리 위치 , 머리위치를 기준으로 나머지 부분 길이 재기
	// 왼쪽팔 재기
	int a = x + 1, b = y - 1;
	while (cookie[a][b] == '*') {
		la++;
		b--;
	}
	// 오른쪽팔 재기
	a = x + 1, b = y + 1;
	while (cookie[a][b] == '*') {
		ra++;
		b++;
	}
	// 허리 재기
	a = x + 2, b = y;
	while (cookie[a][b] == '*') {
		w++;
		a++;
	}
	// 왼쪽 다리 재기
	a = x + w + 2, b = y - 1;
	while (cookie[a][b] == '*') {
		ll++;
		a++;
	}
	// 오른쪽 다리 재기
	a = x + w + 2, b = y + 1;
	while (cookie[a][b] == '*') {
		rl++;
		a++;
	}
	
	cout << x + 1 << " " << y << "\n";	// 심장 위치 출력
	cout << la << " " << ra << " " << w << " " << ll << " " << rl;
	
	return 0;
}