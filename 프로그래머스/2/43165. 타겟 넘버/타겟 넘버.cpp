#include <string>
#include <vector>

using namespace std;

int result = 0;

void dfs(int num, int idx, vector<int> numbers, int target){
    if(idx == numbers.size()-1){
        if(num + numbers[idx] == target || num - numbers[idx] == target)
            result++;
        return;
    }    
    
    int next_plus = num + numbers[idx];
    dfs(next_plus,idx+1,numbers,target);
    int next_minus = num - numbers[idx];
    dfs(next_minus,idx+1,numbers,target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0,0,numbers,target);
    answer = result;
    
    return answer;
}