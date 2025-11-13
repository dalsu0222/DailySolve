#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
char arr[9]; // 부등호 input 저장
bool visited[10]; // tmp에 대한 visit 여부 저장
vector <string> words;
char tmp[10]; // 최종 숫자배열 저장

bool check(int x){
  for(int i=0 ; i<x-1; i++){ // 부등호 k번째이면 수는 k-1번째까지 유효
    int num1 = tmp[i] - '0';
    int num2 = tmp[i+1] - '0';
    //cout << "[debug1] num1 :" << num1 << ", num2: " << num2 << "\n";
    if(arr[i] == '<' && num1 > num2)
      return false;
    
    if(arr[i] == '>' && num1 < num2)
      return false;
  }
  return true;
}

void dfs(int x){
  if(x > 0 && !check(x)){
    return;
  }
  if(x == k+1){ // 부등호 k개, 숫자는 k+1개개
    // char -> string 변환
    string result = "";
    for(int i=0 ; i<k+1 ; i++){
      result += tmp[i];
    }
    
    // vector에 추가
    words.push_back(result);
    
    return;
  }
  
  for(int i=0 ; i<=9 ; i++){
    if(visited[i])  continue;
    visited[i] = true;
    tmp[x] = '0' + i;
    dfs(x+1);
    visited[i] = false;
  }
  
  return;
  
}





int main() 
{
    cin >> k;
    for(int i=0 ; i<k; i++){
      cin >> arr[i];
    }
    
    dfs(0);
    
    sort(words.begin(),words.end());
    cout << words[words.size()-1] << "\n" << words[0];
    
    
    return 0;
}