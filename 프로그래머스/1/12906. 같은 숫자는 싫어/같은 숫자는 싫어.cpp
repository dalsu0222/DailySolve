#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int n = arr.size();
    
    answer.push_back(arr[0]);
    
    for(int i=1 ; i<n ; i++){
        if(arr[i-1] == arr[i])   continue;
        answer.push_back(arr[i]);
    }
    
    return answer;
}