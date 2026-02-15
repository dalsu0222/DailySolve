#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 백트래킹으로 모든 경우의 수 구하거나
// a+b> b+a 로 람다 비교식 써서 정렬 후 정답 구하기

bool compare(const string &a, const string &b){
    if(a+b > b+a) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    
    for(int i=0 ; i<numbers.size(); i++){
        string s = to_string(numbers[i]);
        nums.push_back(s);
    }
    
    sort(nums.begin(), nums.end(), compare);
    for(int i=0 ; i<nums.size(); i++){
        answer += nums[i];
    }
    
    // [0,0] 과 같이 0만 들어오는 케이스도 고려
    if(answer[0] == '0')
        answer = "0"; 
    
    return answer;
}