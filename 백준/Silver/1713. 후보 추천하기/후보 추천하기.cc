#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> frame; // 후보
int cnt[101]; // cnt[i]: 후보 i의 추천수
int t[101]; // t[i]: 후보 i가 등장한 시간


int main() 
{
    cin >> n >> m;
    int num;
    for(int i=0 ; i<m ; i++){
      cin >> num;
      // 이미 있는 경우
      if(cnt[num] > 0){
        cnt[num]++;
        continue;
      }
      
      if(frame.size() < n){  // 비어있는 사진 틀이 있는 경우
       frame.push_back(num);
       cnt[num] = 1;
       t[num] = i;
      }
      else{ // 비어있는 사진 틀이 없는 경우
        int removeIdx = 0;
        for(int j=1 ; j<n ; j++){
          int n1 = frame[removeIdx];
          int n2 = frame[j];
          
          if(cnt[n1] > cnt[n2]){
            removeIdx = j;
          }
          else if(cnt[n1] == cnt[n2] && t[n1] > t[n2]){
            removeIdx = j;
          }
        }
        
        // 제거
        int target = frame[removeIdx];
        cnt[target] = 0;
        t[target] = -1;
        frame.erase(frame.begin() + removeIdx);
        
        // 새로운 후보 넣기
        frame.push_back(num);
        cnt[num] = 1;
        t[num] = i;
      }
    }
    
    sort(frame.begin(), frame.end());
    for(int i=0 ; i< frame.size() ; i++){
      cout << frame[i] << " ";
    }
    
    
    return 0;
}