#include<iostream>

using namespace std;
int n, k;
int map[1000][1000];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1, 0,-1 };
int dir;	// 방향

int main()
{
	cin >> n >> k;
	
	int rx = n / 2, ry = n / 2;	// 찾고자 하는 수의 좌표 값
	int x = n / 2, y = n / 2;	// 직전 좌표 값
	map[x][y] = 1;
	int num = 2;
	int length = 1;
	while (num <= n * n) {
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < length; j++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				map[nx][ny] = num;
				if (num == k) {	// 찾고자 하는 좌표를 찾았다면, 위치 저장
					rx = nx;
					ry = ny;
				}
				num++;
				x = nx;	y = ny;	// 직전 자리의 좌표
				if (num > n * n)		// 종료 조건
					break;
			}
			
			dir = (dir + 1) % 4;	// dir 값 : 0~3 반복
			if (num > n * n)		// 종료 조건
				break;
			
		}
		length++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << rx + 1 << " " << ry + 1;

	return 0;
}