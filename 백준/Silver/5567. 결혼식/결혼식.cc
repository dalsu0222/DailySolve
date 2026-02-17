#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;

vector<int> v[501];
bool visited[501];
int answer;

void find_friends(int x){
  visited[x] = true;
  queue<pair<int,int>> q; // (번호, 깊이)
  q.push({x,0});
  
  while(!q.empty()){
    auto tmp = q.front();
    int num = tmp.first;
    int d = tmp.second;
    q.pop();
    if(d >= 2) continue;
    
    for(int i=0 ; i<v[num].size(); i++){
      int num2 = v[num][i];
      if(visited[num2]) continue;
      
      q.push({num2,d+1});
      visited[num2] = true;
      answer++;
    }
  }

}

int main() 
{
    cin >> n >> m;
    int a,b;
    for(int i=0 ; i<m; i++){
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    
    find_friends(1);
    
    cout << answer;
    
    return 0;
}