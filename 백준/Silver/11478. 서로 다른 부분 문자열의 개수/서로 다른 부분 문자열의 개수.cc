#include <iostream>
#include <set>
using namespace std;

string s;
set<string> words;
int result;


int main() 
{
    cin >> s;
    
    for(int i=0 ; i<s.length() ; i++){// 시작점
      string tmp = "";
      for(int j=i ; j<s.length() ; j++){ // 끝 인덱스
        tmp += s[j];
        words.insert(tmp);
      }
    }
    
    cout << words.size();
    
    return 0;
}