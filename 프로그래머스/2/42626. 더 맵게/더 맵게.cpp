#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0 ; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    // 힙에 음식이 1개만 있으면 더이상 만들 수 없으므로 반드시 사이즈 체크
    while(pq.size() >=2 && pq.top() < K){
        int s0 = pq.top();
        pq.pop();
        int s1 = pq.top();
        pq.pop();
        int newS = s0 + s1*2;
        pq.push(newS);
        
        answer++;
    }
    
    if(pq.top() < K)
        answer = -1;
    
    return answer;
}