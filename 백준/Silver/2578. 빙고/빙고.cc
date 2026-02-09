#include <iostream>
#include <unordered_map>
using namespace std;

int input[25];
int cnt_x[5]; // 가로
int cnt_y[5]; // 세로
int cnt_d1; // \ 대각선
int cnt_d2; // / 대각선
int bingo_cnt;

unordered_map<int,pair<int,int>> mapping;

bool isXFinished(int x){
  return cnt_x[x] == 5 ? true : false;
}

bool isYFinished(int y){
  return cnt_y[y] == 5 ? true : false;
}

bool isD1Finished(){
  return cnt_d1 == 5 ? true : false;
}

bool isD2Finished(){
  return cnt_d2 == 5 ? true : false;
}

int main() 
{
    int tmp;
    for(int i=0 ; i<5; i++){
      for(int j=0 ; j<5; j++){
        cin >> tmp;
        mapping[tmp] = make_pair(i,j);
      }
    }
    
    for(int i=0 ; i<25; i++){
      cin >> input[i];
    }
    
    
    for(int i=0 ; i<25; i++){
      int target = input[i];
      int x = mapping[target].first;
      int y = mapping[target].second;
      cnt_x[x]++;
      cnt_y[y]++;
      // 한 줄이 완성됐는지 검사
      if(isXFinished(x)) bingo_cnt++;
      if(isYFinished(y)) bingo_cnt++;
      
      if(x+y == 4){
        cnt_d2++;
        if(isD2Finished()) bingo_cnt++; // 대각선 검사
      }
      if(x == y){
        cnt_d1++;
        if(isD1Finished()) bingo_cnt++;  // 대각선 검사
      }
      
      // 빙고인지 검사
      if(bingo_cnt >= 3){
        cout << i+1;
        break;
      }
    }
    
    return 0;
}