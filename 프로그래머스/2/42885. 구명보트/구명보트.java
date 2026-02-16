import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        // 투포인터 느낌으로 접근
        Arrays.sort(people);
        int idx = 0; // 맨 앞 사람 인덱스
        for(int i= people.length-1 ; i>=idx ; i--){
            if(people[idx] + people[i] <= limit){
                answer++; // 같이 타기
                idx++;
            }else{
                answer++; // 맨 뒷사람만 단독으로 타기
            }
        }
        
        return answer;
    }
}