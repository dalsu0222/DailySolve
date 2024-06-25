function solution(maps) {
  var n = maps.length;
  var m = maps[0].length;
  var dx = [-1, 1, 0, 0]; // 상 하 좌 우
  var dy = [0, 0, -1, 1];

  var bfs = () => {
    var queue = [[0, 0, 1]]; // x,y,d(이동거리)
    maps[0][0] = 0; // 방문처리

    while (queue.length > 0) {
      var [x, y, cnt] = queue.shift(); // 구조분해할당
      if (x === n - 1 && y === m - 1) return cnt; // 목적지 도착
      for (var i = 0; i < 4; i++) {
        var nx = x + dx[i];
        var ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          // map 밖을 벗어나는경우, 무시
          continue;
        if (maps[nx][ny] === 1) {
          queue.push([nx, ny, cnt + 1]);
          maps[nx][ny] = 0; // 방문처리
        }
      }
    }
    return -1;
  };
  return bfs();
}
// console.log(
//   solution([
//     [1, 0, 1, 1, 1],
//     [1, 0, 1, 0, 1],
//     [1, 0, 1, 1, 1],
//     [1, 1, 1, 0, 1],
//     [0, 0, 0, 0, 1],
//   ])
// );
// console.log(
//   solution([
//     [1, 0, 1, 1, 1],
//     [1, 0, 1, 0, 1],
//     [1, 0, 1, 1, 1],
//     [1, 1, 1, 0, 0],
//     [0, 0, 0, 0, 1],
//   ])
// );
