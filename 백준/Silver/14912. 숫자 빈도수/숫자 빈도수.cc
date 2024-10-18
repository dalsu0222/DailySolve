#include <iostream>
#include <string>

using namespace std;
 
int main(void){
 
    int n;
    char check;
    cin >> n >> check;
    int cnt = 0;
 
    for(int i = 1;i<=n;i++){
        string str = to_string(i); // 1. string형태로 바꿔주기
        for(int j = 0;j<str.size();j++){ // 2. check와 같다면 cnt증가
            if(str[j] == check){
                cnt++;
            }
        }
    }
    cout << cnt; // 3. 결과출력
}