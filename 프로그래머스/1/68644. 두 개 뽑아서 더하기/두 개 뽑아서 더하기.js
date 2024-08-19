function solution(numbers) {
  var arr = [];
  var n = numbers.length;
  for (var i = 0; i < n; i++) {
    for (var j = i + 1; j < n; j++) {
      var sum = numbers[i] + numbers[j];
      arr.push(sum);
    }
  }
  var answer = [...new Set(arr)];
  answer.sort((a, b) => a - b);

  return answer;
}