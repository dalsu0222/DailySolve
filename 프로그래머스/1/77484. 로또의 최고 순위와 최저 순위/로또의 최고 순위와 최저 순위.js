function solution(lottos, win_nums) {
  let answer = [];
  let zero = lottos.filter((v) => v === 0).length;
  let count = 0;
  lottos.forEach((v) => {
    if (win_nums.includes(v)) {
      count++;
    }
  });
  answer.push(7 - (count + zero) > 6 ? 6 : 7 - (count + zero)); // 최고 순위
  answer.push(7 - count > 6 ? 6 : 7 - count); // 최저 순위
  //console.log(answer);
  return answer;
}
