#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int x, y;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;	// 월 일 입력
	int daysum = 0;		// x월 y일까지 총 일수 계산하여 저장
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= 31; j++) {
			daysum++;
			if (x == i && y == j)
				break;
			if (i == 2 && j == 28)
				break;
			if ((i == 4 || i == 6 || i == 9 || i == 11) && j == 30)
				break;
		}
	}

	int result = daysum % 7;
	switch(result) {	// 7로 나눈 나머지에 따라 요일 판별(mod 7)
	case 1: cout << "MON"; break;
	case 2: cout << "TUE"; break;
	case 3: cout << "WED"; break;
	case 4: cout << "THU"; break;
	case 5: cout << "FRI"; break;
	case 6: cout << "SAT"; break;
	case 0: cout << "SUN"; break;
	}

	return 0;
}
