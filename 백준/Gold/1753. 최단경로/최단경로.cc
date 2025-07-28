#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define MAX 20001
using namespace std;

vector<pair<int,int>> dist[MAX];
long long minw[MAX];
int v,e,k;

void dijkstra(int start){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0, start});
  minw[start] = 0;
  
  while(!pq.empty()){
    int node_w = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    
    // 이미 더 짧은 값으로 갱신된 경우, 무시
    if(minw[node] < node_w)
      continue;
    
    // node의 이웃노드 탐색
    for(int i=0 ; i<dist[node].size() ; i++){
      int newn = dist[node][i].first; // 이웃 노드
      int neww = dist[node][i].second;
      if(minw[newn] > neww + node_w){ // 거쳐서 가는게 더 빠른경우
        minw[newn]= neww + node_w;
        pq.push({neww + node_w, newn});
      }
    }
  }
}

// 시작 정점부터 다른 정점까지의 최단 경로 -> 다익스트라
int main()
{
    cin >> v >> e >> k;
    int v1,v2,w;
    fill(minw, minw + MAX, INT_MAX);
    for(int i=0 ; i<e ; i++){
        cin >> v1 >> v2 >> w;
        dist[v1].push_back({v2,w});
    }
    
    dijkstra(k);
    
    for(int i=1 ; i<=v ; i++){
      if(minw[i] == INT_MAX)
        cout << "INF\n";
      else
        cout << minw[i] << "\n";
    }

    return 0;
}