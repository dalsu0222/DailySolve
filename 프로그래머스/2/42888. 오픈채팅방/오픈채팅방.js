function solution(record) {
  var answer = [];

  const user = {}; // uid - 닉네임 쌍을 저장하는 객체
  // 기록을 바탕으로 uid-닉네임 매칭 및 수정
  for (const rec of record) {
    const recfrag = rec.split(" ");
    const word = recfrag[0];
    const uid = recfrag[1];
    if (word === "Enter" || word === "Change") {
      user[uid] = recfrag[2];
    }
  }

  for (const rec of record) {
    const recfrag = rec.split(" ");
    const word = recfrag[0];
    const nickname = user[recfrag[1]];
    if (word === "Enter") {
      answer.push(`${nickname}님이 들어왔습니다.`);
    } else if (word === "Leave") {
      answer.push(`${nickname}님이 나갔습니다.`);
    }
  }

  return answer;
}