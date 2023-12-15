#include <iostream>
#include <string>
#include <string.h>
using namespace std;
 
int main(){
    
    int N; cin >> N;
    string str;
    
    char result[50];        
    
    cin >> str;
    
    for(int i = 0; i<str.length(); i++)  // 가장 처음 입력받은 문자열로 초기화
        result[i] = str[i];
    
    for(int i = 1; i<N; i++){
        cin >> str;
        for(int s = 0; s<str.length(); s++){        // 다른 부분이 발견된다면 '?'로 변경
            if(result[s] != str[s]) 
                result[s] = '?';
        }
    }
    for(int i = 0; i<str.length(); i++) cout << result[i];
    
    return 0;
}