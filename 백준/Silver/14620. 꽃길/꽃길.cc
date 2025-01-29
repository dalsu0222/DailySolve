#include<iostream>
#include<string>

using namespace std;

int n;
int map[11][11];
int price[3];
bool isPlanted[11][11];
int min_p = 99999;

int calc_price(int x, int y) {
    int total = 0;
    total += map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y - 1] + map[x][y + 1];
    return total;
}

void do_plant(int x, int y) {
    isPlanted[x][y] = isPlanted[x - 1][y] = isPlanted[x + 1][y] = isPlanted[x][y - 1] = isPlanted[x][y + 1] = true;
}

void un_plant(int x, int y) {
    isPlanted[x][y] = isPlanted[x - 1][y] = isPlanted[x + 1][y] = isPlanted[x][y - 1] = isPlanted[x][y + 1] = false;
}

bool can_plant(int x, int y) {
    // 지금까지 심은 씨앗의 위치로 범위판별하면, 더 효율적일듯
    // 하나라도 심어져 있는 상태라면, false 반환
    return !(isPlanted[x][y] || isPlanted[x - 1][y] || isPlanted[x + 1][y] || isPlanted[x][y - 1] || isPlanted[x][y + 1]);
}

void dfs(int cnt) {
    if (cnt == 3) {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += price[i];
        }
        if (min_p > total) {
            min_p = total;
        }
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            // 심는게 가능한 자린지 확인
            bool land = can_plant(i, j);
            if (!land) {
                continue;
            }
            int total = calc_price(i, j);
            price[cnt] = total;
            do_plant(i, j);
            dfs(cnt + 1);
            un_plant(i, j);
            
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0);

    cout << min_p;

    return 0;
}
