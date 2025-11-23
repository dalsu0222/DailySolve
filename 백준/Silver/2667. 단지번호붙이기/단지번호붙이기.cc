#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int input[25][25];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool visited[25][25];
vector<int> apt;

int bfs(int x, int y){
  queue<pair<int,int>> q; // (x,y)
  visited[x][y] = true;
  q.push({x,y});
  
  int cnt = 1; // 영역의 넓이 카운트
  
  while(!q.empty()){
    int curx = q.front().first;
    int cury = q.front().second;
    q.pop();
    for(int i=0 ; i<4 ; i++){
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if(nx < 0 || ny < 0 || nx >= n || ny >= n
       || visited[nx][ny] || input[nx][ny] == 0)
        continue;
      q.push({nx,ny});
      visited[nx][ny] = true;
      cnt++;
    }
  }
  
  return cnt;
}


int main() 
{
    cin >> n;
    for(int i=0 ; i<n ; i++){
      string s;
      cin >> s;
      for(int j=0 ; j<n ; j++){
        input[i][j] = s[j] - '0';
      }
    }
    
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<n ; j++){
        if(!visited[i][j] && input[i][j] == 1){
          int result = bfs(i,j);
          apt.push_back(result);
        }
      }
    }
    
    sort(apt.begin(),apt.end());
    
    cout << apt.size() << "\n";
    for(int i=0 ; i<apt.size() ; i++){
      cout << apt[i] << "\n";
    }
    
    
    return 0;
}