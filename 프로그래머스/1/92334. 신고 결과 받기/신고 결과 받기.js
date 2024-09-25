function solution(id_list, report, k) {
  var answer = [];
  const reportObj = {}; // 키: 신고당한사람, 값: 신고한사람 모음(중복제외하기위해 Set 이용)
  const mailObj = {}; // 키: 유저이름, 값: 메일받는 횟수
  for (const rep of report) {
    const [name1, name2] = rep.split(" ");
    if (!(name2 in reportObj)) {
      reportObj[name2] = new Set();
    }
    reportObj[name2].add(name1);
  }
  for (const person of Object.keys(reportObj)) {
    if (reportObj[person].size >= k) {
      for (let name of reportObj[person]) {
        mailObj[name] = (mailObj[name] || 0) + 1; // 별도 초기화대신 || 이용
      }
    }
  }

  for (const name of id_list) {
    answer.push(mailObj[name] || 0);
  }
  return answer;
}