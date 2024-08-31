function solution(s) {
  var answer = 0;
  for (let i = 0; i < s.length; i++) {
    let stack = [];
    let isCorrect = true;
    for (let j = 0; j < s.length; j++) {
      let ch = s[(i + j) % s.length];
      if (ch === "(" || ch === "[" || ch === "{") {
        stack.push(ch);
      } else {
        if (stack.length === 0) {
          // 열린 괄호가 남아있는 경우
          isCorrect = false;
          break;
        }
        if (ch === ")" && stack[stack.length - 1] === "(") {
          stack.pop();
        } else if (ch === "]" && stack[stack.length - 1] === "[") {
          stack.pop();
        } else if (ch === "}" && stack[stack.length - 1] === "{") {
          stack.pop();
        } else {
          isCorrect = false;
          break;
        }
      }
    }
    if (isCorrect && stack.length === 0) {
      answer++;
    }
  }

  return answer;
}