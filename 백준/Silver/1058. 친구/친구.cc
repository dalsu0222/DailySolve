#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50

using namespace std;

// 내가 알고있는 사람들중에, 
// 내가 모르는 사람을 알고있으면 그사람이랑도 친구임
int main()
{
    int n;
    cin >> n;
    
    char map[MAX + 1][MAX + 1];
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> map[i][j];
        }
    }
    
    int max_c = 0;
    for(int i=1 ; i<=n ; i++){
        int c = 0;
        vector<int> know;
        bool visited[MAX + 1] = { false };
        
        // 직접 친구
        for(int j=1 ; j<=n ; j++){
            if(j == i) continue;
            
            if(map[i][j] == 'Y'){
                c++;
                know.push_back(j);
            }
        }
        
        for(int j=1 ; j<=n ; j++){
            if(j == i) continue;
            
            // j 가 중복이 되면 안됨
            if(map[i][j] == 'N'){
                for(int k=0 ; k<know.size() ; k++){
                    if(map[know[k]][j] == 'Y' && !visited[j]){
                        c++;
                        visited[j] = true;
                    }
                }
            }
        }
        
        max_c = max(max_c, c);
    }
    
    cout << max_c;
    
    return 0;
}