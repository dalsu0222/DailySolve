#include<iostream>
#include<string>

using namespace std;

int n, k;
string input[51];
char arr[51];
bool learned[26]; // 알파벳 배웠는지 여부
int max_r = 0;

void dfs(int idx, int cnt) {
    if (cnt == k) {
        // 읽을 수 있는 단어 세기
        int result = 0;
        for (int i = 0; i < n; i++) {
            bool isRead = true;
            for (int j = 4; j < input[i].size() - 4; j++) {
                if (!learned[input[i][j] - 'a']) {
                    isRead = false;
                    break;
                }
            }
            if (isRead) {
                result++;
            }
        }
        max_r = max(result, max_r);

        return;
    }
    // 알파벳순으로 최대 26번 탐색
    for (int i = idx; i < 26; i++) {
        if (learned[i]) {
            continue;
        }
        learned[i] = true;
        dfs(i + 1, cnt + 1);
        learned[i] = false;
    }

}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    learned['a' - 'a'] = learned['n' - 'a'] = learned['t' - 'a'] = learned['i' - 'a'] = learned['c' - 'a'] = true;
    arr[0] = 'a';   arr[1] = 'n';   arr[2] = 't';   arr[3] = 'i';   arr[4] = 'c';

    if (k < 5) {
        cout << 0;
        return 0;
    }

    dfs(0,5);

    cout << max_r;

    return 0;
}
