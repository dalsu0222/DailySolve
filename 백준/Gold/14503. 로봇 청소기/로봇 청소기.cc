#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int x, y, di;
int room[51][51];
bool cleaned[51][51];
int cnt;	// 청소하는 방의 개수(결과)

int main(void)
{
	cin >> N >> M;
	cin >> x >> y >> di;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}

	int nx = x; int ny = y; int ndi = di;
	while (1) {
		// 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
		if (room[nx][ny] == 0 && !cleaned[nx][ny]) {
			cnt++;
			cleaned[nx][ny] = true;
		}

		// 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
		if (room[nx - 1][ny] == 0 && !cleaned[nx - 1][ny] ||
			room[nx][ny + 1] == 0 && !cleaned[nx][ny + 1] ||
			room[nx + 1][ny] == 0 && !cleaned[nx + 1][ny] ||
			room[nx][ny - 1] == 0 && !cleaned[nx][ny - 1]) {
			//3-1. 반시계 방향으로 90도 회전
			ndi--;
			if (ndi == -1)	// 북(0) - > 서(3)
				ndi = 3;
			//3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진
			if (ndi == 0) {
				if (room[nx - 1][ny] == 0 && !cleaned[nx - 1][ny]) {
					nx = nx - 1;
				}
			}else if (ndi == 1) {
				if (room[nx][ny+1] == 0 && !cleaned[nx][ny+1]) {
					ny = ny + 1;
				}
			}
			else if (ndi == 2) {
				if (room[nx + 1][ny] == 0 && !cleaned[nx + 1][ny]) {
					nx = nx + 1;
				}
			}
			else if (ndi == 3) {
				if (room[nx][ny - 1] == 0 && !cleaned[nx][ny - 1]) {
					ny = ny - 1;
				}
			}
		}
		else {	// 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
			if (ndi == 0) {
				// 2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아가기
				if (room[nx + 1][ny] == 0) {
					nx = nx + 1;
				}
				else {	// 2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다
					break;
				}
			}
			else if (ndi == 1) {
				if (room[nx][ny - 1] == 0) {
					ny = ny - 1;
				}
				else {	
					break;
				}
			}
			else if (ndi == 2) {
				if (room[nx - 1][ny] == 0) {
					nx = nx - 1;
				}
				else {
					break;
				}
			}
			else if (ndi == 3) {
				if (room[nx][ny + 1] == 0) {
					ny = ny + 1;
				}
				else {
					break;
				}
			}
		}

	}
	cout << cnt;

	return 0;
}