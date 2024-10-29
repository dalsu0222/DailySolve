#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
int r1, c1, r2, c2;
int map[201][201];
bool visited[201][201];
int cnt;
int dr[6] = { -2,-2,0,0,2,2 };
int dc[6] = { -1,1,-2,2,-1,1 };

void bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({ {r1,c1},0 });
    visited[r1][c1] = true;
   
    while (!q.empty()) {
        pair<pair<int, int>, int> element = q.front();
        pair<int, int> coords = element.first;
        int dist = element.second;
        int r = coords.first;
        int c = coords.second;
        q.pop();
        if (r == r2 && c == c2) {   // 목표지점에 도달한경우, 최소 이동 횟수 바로 출력
            cout << dist;
            return;
        }
        for (int i = 0; i < 6; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) {
                continue;
            }
            q.push({ {nr,nc},dist + 1 });
            visited[nr][nc] = true;
        }
    }
    cout << -1; // 이동할 수 없는 경우
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    // 최소이동횟수 -> bfs
    bfs();

    return 0;
}