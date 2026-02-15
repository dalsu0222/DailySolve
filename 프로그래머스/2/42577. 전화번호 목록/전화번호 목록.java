import java.util.*;
import java.io.*;

class Solution {
    public boolean solution(String[] phone_book) {
        
        Set<String> s = new HashSet<>();
        for(String number : phone_book){
            s.add(number);
        }
        
        for(String number: phone_book){
            for(int i=1; i<number.length(); i++){
                String pf = number.substring(0,i);
                if(s.contains(pf)){
                    return false;
                }
            }
        }
        
        return true;
    }
}