function solution(n, words) {
    const isWord = {};
    isWord[words[0]] = true;
    for(let i=1 ; i<words.length ; i++){
        const word= words[i];
        const beforeEnd =  words[i-1].charAt(words[i-1].length-1);
        if(isWord[word] || beforeEnd !== word.charAt(0) ){
            return [i%n + 1 , Math.floor(i/n) + 1];
        }else{
            isWord[word] = true;
        }
    }
    return [0,0];
}