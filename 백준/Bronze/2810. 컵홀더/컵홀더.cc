#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
char arr[51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int cnt = 1;
    int temp = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] == 'S')      // 솔로석인경우
            cnt++;
        else {      // 커플석인경우
            temp++;
            if (temp == 2) {    // 커플 2명 모두 카운팅되면, 커플 인원수 다시 초기화 후 컵홀더수 1 증가
                temp = 0;
                cnt++;
            }
        }
    }

    if (cnt > N)        
        cout << N;
    else 
        cout << cnt;

	return 0;
}