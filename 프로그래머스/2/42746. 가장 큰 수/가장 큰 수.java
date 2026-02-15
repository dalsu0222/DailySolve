import java.util.*;
import java.io.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        List<String> s = new ArrayList<>();
        for(int num : numbers){
            s.add(String.valueOf(num));
        }
        
        s.sort((a,b)->(b+a).compareTo(a+b));
        
        StringBuilder sb = new StringBuilder();
        for(String tmp : s){
            sb.append(tmp);
        }
        answer = sb.toString();
        if(answer.charAt(0) == '0')
            answer = "0";
        
        return answer;
    }
}