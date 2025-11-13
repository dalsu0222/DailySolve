#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int a,b;
vector <int> v[101];
bool visited[101];

int bfs(int v1, int v2){
  visited[v1] = true;
  queue<pair<int,int>> q; // {정점, 촌수}
  q.push({v1,0}); // 자기 자신은 0촌
  while(!q.empty()){
    int cv = q.front().first;
    int c = q.front().second;
    q.pop();
    
    for(int i=0 ; i<v[cv].size() ; i++){
      int nv = v[cv][i];
      if(visited[nv])
        continue;
      if(nv == v2)
        return c+1;
      q.push({nv, c+1});
      visited[nv] = true;
    }
  }
  
  return -1;
  
}

int main() 
{
  cin >> n >> a >> b >> m;
  
  for(int i=0 ; i<m ; i++){
    int v1,v2;
    cin >> v1 >> v2;
    
    v[v1].push_back(v2);
    v[v2].push_back(v1);
  }
  
  cout << bfs(a,b);
    
  return 0;
}