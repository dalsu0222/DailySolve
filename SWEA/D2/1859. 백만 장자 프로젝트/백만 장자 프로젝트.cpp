#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    int tc;
    int T, N;

    cin >> T;

    for (tc = 1; tc <= T; ++tc)
    {
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        long long profit = 0;   
        int highv = -1; // 가장 큰 가격을 담고있는 변수
        for (int i = N - 1; i >= 0; i--) {
            if (highv < v[i]) {	// 가장 큰 가격 갱신
                highv = v[i];
            }
            else {      // 가장 큰 가격이 아닐경우 : v[i]가격으로 구매가 이루어지고, highv만큼의 판매가 일어남
                profit -= v[i];
                profit += highv;
            }
        }

        cout << "#" << tc << " " << profit << "\n";
    }
    return 0;
}