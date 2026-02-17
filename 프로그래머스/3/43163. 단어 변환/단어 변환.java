import java.util.*;

class Solution {
    static int answer;
    
    static class Node {
        String word;
        int d; //depth
        
        Node(String word, int d){
            this.word = word;
            this.d = d;
        }
    }
    
    static boolean isDiffOne(String word, String nword){
        int cnt = 0;
        for(int i=0 ; i<word.length(); i++){
            if(word.charAt(i) != nword.charAt(i))
                cnt++;
        }
        return cnt == 1 ? true : false;
    }
    
    static void findTarget(String begin, String target, String[] words){
        boolean[] visited = new boolean[words.length];
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(begin,0));
        // begin은 words에 없기 때문에 방문 체크 x
        
        while(!q.isEmpty()){
            Node tmp = q.poll();
            String word = tmp.word;
            int d = tmp.d;
            
            if(word.equals(target)){
                answer = d;
                break;
            }
            
            for(int i=0 ; i<words.length; i++){
                // word(현재 string)와 한 글자 차이나는 단어인지 체크
                if(!visited[i] && isDiffOne(word,words[i])){
                    visited[i] = true;
                    q.offer(new Node(words[i], d+1));
                }
            }
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        
        // 타겟이 words 안에 있는지 유무 확인
        boolean isTargetInWords = false;
        for(String word: words){
            if(word.equals(target))
                isTargetInWords = true;
        }
        
        if(!isTargetInWords) return 0;
        
        // 최소 변환 수를 찾기 위한 bfs 실행
        findTarget(begin,target,words);
        
        return answer;
    }
}