#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remain;

    // 남은 작업일 수 구하기
    for(int i=0 ; i<progresses.size(); i++){
        remain.push_back(ceil( (100-progresses[i]) / (double)speeds[i] ));
    }
    
    // 큐의 맨 앞과 비교해서 작으면 계속 큐에 넣고 크면 큐 방출, 다시 넣기
    queue<int> pg;
    pg.push(remain[0]);
    for(int i=1; i<remain.size(); i++){
        if(remain[i] <= pg.front()){
            pg.push(remain[i]);
        }else{
            int cnt = pg.size();
            answer.push_back(cnt);
            while (!pg.empty()) pg.pop();
            pg.push(remain[i]);
        }
    }
    if(pg.size() > 0){ //마지막 작업도 추가
        answer.push_back(pg.size());
    }
    
    return answer;
}