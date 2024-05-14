#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;
string str;

int main()
{
    getline(cin, str);  // 공백포함 입력받기
    stack<char> s;
    bool isOpen = false;
    for (int i = 0; i < str.size(); i++) {
        // 태그 안의 문자일 경우
        if (isOpen && (str[i] != '<' && str[i] != '>')) {
            cout << str[i];
            continue;
        }

        // 기호가 아닌, 글자가 온 경우 -> 거꾸로 출력을 위해 스택에 push
        if (str[i] != ' ' && str[i] != '<' && str[i] != '>') { 
            s.push(str[i]);
        }
        else {  // 기호가 온 경우 -> 단어 거꾸로 출력
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            // 공백 처리
            if (str[i] == ' ')
                cout << str[i];

        }

        if (str[i] == '<') {
            isOpen = true;
            cout << str[i];
        }
        else if (str[i] == '>') {
            isOpen = false;
            cout << str[i];
        }
    }
    while (!s.empty()) {    // 남은 단어가 있다면 출력
        cout << s.top();
        s.pop();
    }

    return 0;
}