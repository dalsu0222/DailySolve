function solution(genres, plays) {
  var answer = [];
  let genreObj = {}; // 장르별 [ [id,play] ... ] 저장
  let playObj = {}; // 장르별 총 play수 저장
  for (let i = 0; i < genres.length; i++) {
    const genre = genres[i];
    const play = plays[i];
    if (!genreObj[genre]) {
      genreObj[genre] = [];
      playObj[genre] = 0;
    }
    genreObj[genre].push([i, play]);
    playObj[genre] += play;
  }

  const sortedGenres = Object.keys(playObj).sort((a, b) => {
    return playObj[b] - playObj[a]; // 재생수 내림차순 정렬
  });
  for (const genre of sortedGenres) {
    const topChart = genreObj[genre].sort((a, b) => {
      // 재생수가 동일한 경우, 고유번호가 낮은순대로 return
      return a[1] === b[1] ? a[0] - b[0] : b[1] - a[1];
    });
    // 장르당 max 2개까지만
    answer.push(...topChart.slice(0, 2).map((chart) => chart[0]));
  }

  return answer;
}