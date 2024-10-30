#include <iostream>
#include <vector>
using namespace std;

int n;
string word;
vector<string> v;    // 다른 단어를 담아줄 벡터
 
int main() {
    cin >> n;
    for (int a = 0; a < n; a++) {
        cin >> word;
        if (v.empty()) {
            v.push_back(word);
        }
        bool same = false;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                // 같은 단어가 있다면 search 종료
                if (word == v[i]) {
                    same = true;
                    break;
                }
                // 단어가 같지 않다면 맨 앞글자를 맨뒤로 보내줘서 다시 확인
                else {
                    v[i] = v[i] + v[i].at(0);
                    v[i].erase(v[i].begin());
                }
            }
        }
        // 다르다면 벡터에 추가
        if (same == false) {
            v.push_back(word);
        }
    }
    cout << v.size();
}