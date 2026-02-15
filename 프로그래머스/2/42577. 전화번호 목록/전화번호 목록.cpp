#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    
    set<string> s; // 전화번호 저장
    for(int i=0 ; i<phone_book.size(); i++){
        s.insert(phone_book[i]);
    }
    
    for(int i=0 ; i<phone_book.size(); i++){
        // 1. 각 전화번호 별로 가능한 모든 접두어 만들어서
        for(int j = 1; j < phone_book[i].size(); j++){
            string pf = phone_book[i].substr(0,j);
            // 2. 전화번호부에 있는지 확인
            if(s.find(pf) != s.end()){
                return false;
            }
        }
    }
    
    
    return true;
}