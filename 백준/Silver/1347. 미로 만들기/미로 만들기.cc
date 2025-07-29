#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 102
using namespace std;
int n;
string s;
char map[MAX][MAX];
int dir = 2;  // 위 0  오른쪽 1  아래 2 왼쪽 3
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

int main() 
{
    cin >> n;
    cin >> s;
    fill(&map[0][0], &map[0][0] + MAX*MAX , '#');
    
    int x = MAX/2 - 1; // 50
    int y = MAX/2 - 1;
    map[x][y] = '.';
    
    for(int i=0 ; i<s.size() ; i++){
      char c = s[i];
      if(c == 'L'){
        dir = (dir + 3) % 4; // 음수를 만들면 안되니 dir-- 보다는 dir + 3 접근이 올바름
      }else if(c == 'R'){
        dir = (dir + 1) % 4;
      }else{ // c == 'F'
        x += dx[dir];
        y += dy[dir];
        map[x][y] = '.'; // 이동 후 점 남기기
      }
    }
    
    // 지나간 곳의 최소/최대 좌표 찾기
    int maxX = 0, minX = MAX, maxY = 0, minY = MAX;
    for(int i=0 ; i<MAX ; i++){
      for(int j=0 ; j<MAX ; j++){
        if(map [i][j] == '.'){
          minX = min(minX, i);
          maxX = max(maxX, i);
          minY = min(minY, j);
          maxY = max(maxY, j); 
        }
      }
    }
    
    for(int i=minX ; i<=maxX ; i++){
      for(int j=minY ; j<=maxY ; j++){
        cout << map[i][j];
      }
      cout << "\n";
    }
    
    
    return 0;
}