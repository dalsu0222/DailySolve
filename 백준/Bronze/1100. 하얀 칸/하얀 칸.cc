#include <iostream>
using namespace std;

char chess[8][8];
int main() {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> chess[i][j];
			if (((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))&&chess[i][j]=='F') {
				// 흰색 칸에 말이 위치하는 경우(짝수행의 짝수번째 말, 홀수행의 홀수번째 말)
                result++;
			}
		}
	}
	cout << result;
}