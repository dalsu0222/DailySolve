#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    double h, w, n, m;
    cin >> h >> w >> n >> m;

    // 결과 : 세로에 앉은 인원 * 가로에 앉은 인원
    cout << (long long)ceil(h / (n + 1)) * (long long)ceil(w / (m + 1));

	return 0;
}