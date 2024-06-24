var index = 0; // arr1,2,3 을 순회하는 인덱스
function solution(answers) {
  var arr1 = [1, 2, 3, 4, 5];
  var arr2 = [2, 1, 2, 3, 2, 4, 2, 5];
  var arr3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
  var cnt1 = 0;
  var cnt2 = 0;
  var cnt3 = 0;
  for (var i = 0; i < answers.length; i++) {
    if (answers[i] === arr1[index % 5]) {
      cnt1++;
    }
    if (answers[i] === arr2[index % 8]) {
      cnt2++;
    }
    if (answers[i] === arr3[index % 10]) {
      cnt3++;
    }
    index++;
  }
  var answer = [];
  var tmp = [cnt1, cnt2, cnt3];
  const max_c = Math.max(cnt1, cnt2, cnt3); // 최고점찾기 -> Math.max() 사용
  for (var i = 0; i < 3; i++) {
    // 최고점을 맞힌 사람 찾기
    if (max_c === tmp[i]) answer.push(i + 1);
  }
  //console.log(answer);
  return answer;
}