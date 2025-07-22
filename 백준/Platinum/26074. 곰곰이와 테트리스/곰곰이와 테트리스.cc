#include <iostream>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    if (N * M == 2) cout << "ChongChong";
    else cout << "GomGom";
}
