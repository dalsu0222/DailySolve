#include<iostream>
#include<vector>


using namespace std;
int n;

int main()
{
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {   // 키 : i+1
        cin >> input[i];
    }

    /*
        키가 작은 사람부터 시작하여(i=0 -> 키 1에 해당)
        설 수 있는 자리 찾기
    */
    vector<int> ans(n); // 자동으로 0으로 초기화
    for (int i = 0; i < n; i++) {
        int index = 0;
        while (input[i] != 0) {
            if (ans[index] == 0) {  // 설수있는 자리라면 count
                input[i]--;
            }
            index++;
        }
        while (ans[index] != 0) {   // 서야하는자리에 누가 있다면 pass
            index++;
        }
        ans[index] = i + 1; // i+1 키를 가진 학생이 줄서기
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}