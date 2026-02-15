import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] citations) {
        int hIndex = citations[citations.length-1];
        
        Arrays.sort(citations); // 오름차순
        for(; hIndex >= 0 ; hIndex--){
            // h번 이상 인용된 논문이 h편 이상인지 확인
            int cntUp = 0;
            for(int i=0 ; i<citations.length; i++){
                if(citations[i] >= hIndex)
                    cntUp++;
            }
            // 나머지 논문이 h번 이하 인용인지 확인
            int cntDown = citations.length - cntUp;
            
            if(cntUp >= hIndex && cntDown <= hIndex)
                break;
        }
        
        return hIndex;
    }
}