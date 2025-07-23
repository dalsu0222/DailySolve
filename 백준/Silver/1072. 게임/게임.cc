#include <iostream>

using namespace std;
long long x,y;

int main()
{
    cin >> x >> y;
    
    
    long long z = (y * 100) / x;
    if(z >= 99){
        cout << -1;
        return 0;
    }
    long long start = 0, end = 1e9;
    long long mid;
    while(start <= end){
        mid = (start + end) / 2;	
		if ((y + mid) * 100 / (x + mid) <= z) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
    }
    
    cout << start;

    return 0;
}