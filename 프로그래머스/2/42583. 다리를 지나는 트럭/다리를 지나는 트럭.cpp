#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int onBridgeW = 0;
    queue<int> q; // 다리 위 트럭들 관리, 다리 길이만큼 큐 길이 유지
    for(int i=0 ; i<bridge_length; i++){
        q.push(0);
    }
    
    for(int t=1; ; t++){
        
        // 하차
        if(!q.empty()){
            int topW = q.front();
            q.pop();
            onBridgeW -= topW;
        }
        
        // 종료
        if(onBridgeW == 0 && truck_weights.size() == 0){
            answer = t;
            break;
        }
        
        // 상차
        if(truck_weights.size() > 0 && (onBridgeW + truck_weights[0] <= weight)){
            q.push(truck_weights[0]);
            onBridgeW += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }else{
            q.push(0);
        }
    }
    
    
    return answer;
}