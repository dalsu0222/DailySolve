#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, k, l, t;
char c;
int apple[101][101];	// 사과의 위치를 저장
bool map[101][101];	// 뱀의 몸통이 존재하는지 저장(자기 몸통에 부딪치는지 알기위함)
int dx[4] = { 0, 1, 0, -1 }; // 우, 하, 좌, 상
int dy[4] = { 1, 0, -1, 0 };

/* 
뱀의 꼬리부분은 지나간 자리중 가장 먼저지나간(가장 오래된) 자리이기 때문에,
FIFO 가 적용된 큐를 이용하여 관리함
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	int row, col;
	for (int i = 0; i < k; i++) {
		cin >> row >> col;
		apple[row][col] = 1;
	}

	int sec = 0;	int dir = 0;
	cin >> l;
	int x = 1;	int y = 1;
	queue<pair<int, int>> q;	// 뱀의 몸통을 담고있는 큐
	q.push({ x,y });	// 시작 지점 추가
	for (int i = 0; i < l; i++) {
		cin >> t >> c;
		while (sec < t || i == l - 1) {	// 마지막 이동(i==l-1)일때는 종료될때까지 계속 이동
			sec++;
			int nx = x + dx[dir];	// 다음 위치
			int ny = y + dy[dir];
			if (nx < 1 || nx > n || ny < 1 || ny > n || map[nx][ny]) {	// 게임종료조건
				cout << sec;
				return 0;
			}
			else {
				if (apple[nx][ny] == 1) {	// 다음 위치에 사과가 있을 때
					q.push({ nx,ny });	// 뱀의 몸통에 다음 위치 추가
					apple[nx][ny] = 0;	// 먹은 사과는 없애주기
					map[nx][ny] = true;	// 뱀의 몸통이 존재함을 좌표에맞게 갱신
				}
				else {
					// 뱀의 몸통에 다음 위치 추가
					q.push({ nx,ny });	
					map[nx][ny] = true;
					// 뱀의 꼬리부분 없애기
					map[q.front().first][q.front().second] = false;
					q.pop();	
				}
			}
			// 방향 전환 유무 확인
			if (sec == t) {	// 반복문 빠져나오기 직전(t초에 도달), 방향 틀기
				dir = c == 'D' ? (dir + 1) % 4 : (dir + 3) % 4;
			}
			x = nx;	y = ny;

		}
	}

	
	return 0;
}
