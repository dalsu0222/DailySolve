import java.util.*;
import java.io.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        Map<String, Integer> m = new HashMap<>();
        for(String name : participant){
            m.put(name, m.getOrDefault(name, 0) + 1);
        }
        
        for(String name : completion){
            if(m.containsKey(name)){
                m.put(name, m.get(name)-1);
            }
        }
        
        for(String name: m.keySet()){
            if(m.get(name) != 0){
                answer = name;
                break;
            }
        }
        
        return answer;
    }
}