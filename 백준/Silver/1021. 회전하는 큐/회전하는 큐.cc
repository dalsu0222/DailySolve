#include <iostream>
#include <deque>
using namespace std;

int n, m, result = 0;
deque<int> q;

int main() {
    cin >> n >> m;
    // 1. 큐 초기화
    for (int i = 1; i <= n; i++) {
        q.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;

        int idx = 0;
        // 타겟의 현재 인덱스를 찾음
        for (int j = 0; j < q.size(); j++) {
            if (q[j] == input) {
                idx = j;
                break;
            }
        }

        // 왼쪽이 더 가깝다면 왼쪽으로 이동
        // 절반에서 왼쪽에 있으면 왼쪽으로 이동하는게 이득이다
        if (idx <= q.size() / 2) {
            while (q.front() != input) {
                q.push_back(q.front());
                q.pop_front();
                result++;
            }
        } else {
            while (q.front() != input) {
                q.push_front(q.back());
                q.pop_back();
                result++;
            }
        }

        // 타겟 제거
        q.pop_front();
    }

    cout << result << '\n';
    return 0;
}
