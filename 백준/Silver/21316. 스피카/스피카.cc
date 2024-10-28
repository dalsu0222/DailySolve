#include <iostream>
#include <vector>

using namespace std;
int adj[13][13];
int degree[13];

void spica() {
    for (int i = 1; i <= 12; i++) {
        // 인접 노드 3개가 각각 차수가 1,2,3 이면 spica.
        bool first = false;
        bool second = false;
        bool third = false;

        if (degree[i] == 3) {
            for (int j = 1; j <= 12; j++) {
                if (adj[i][j] && degree[j] == 1) first = true;
                if (adj[i][j] && degree[j] == 2) second = true;
                if (adj[i][j] && degree[j] == 3) third = true;
            }
        }
        if (third && second && first) cout << i;
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 12; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;  // 인접 노드로 추가
        adj[y][x] = 1;
        degree[x]++;    // 노드의 차수 증가
        degree[y]++;
    }

    spica();

    return 0;
}