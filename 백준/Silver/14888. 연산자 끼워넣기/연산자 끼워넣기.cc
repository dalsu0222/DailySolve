#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int A[101];
int oper[4];
int arr[12];

long long max_t = -1000000001;
long long min_t = 1000000001;

void dfs(int cnt) {
    if (cnt == n - 1) {
        long long total = A[0];
        for (int i = 0; i < n - 1; i++) {
            switch (arr[i]) {
                case 0: 
                    total += A[i + 1];
                    break;
                case 1:
                    total -= A[i + 1];
                    break;
                case 2:
                    total *= A[i + 1];
                    break;
                case 3:
                    total /= A[i + 1];
                    break;
            }
        }
        if (total > max_t) {
            max_t = total;
        }
        if (total < min_t) {
            min_t = total;
        }

        return;
    }
    for (int i = 0; i < 4; i++) {
        if (oper[i] <= 0) {
            continue;
        }
        arr[cnt] = i;   // 연산자 기입
        oper[i]--;  // 연산자 사용
        dfs(cnt + 1);
        oper[i]++;  // 사용 해제
        arr[cnt] = 0;   // 연산자 기입 해제
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    dfs(0);

    cout << max_t << "\n" << min_t;

    return 0;
}