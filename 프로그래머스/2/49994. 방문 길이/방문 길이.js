// 좌표평면을 벗어나는지 체크하는 함수
function isValidMap(x,y) { 
  return x >= -5 && x <= 5 && y >= -5 && y <= 5;
}
// 명령어를 바탕으로 다음좌표 결정하는 함수
function updateLocation(x,y,dir){
    switch(dir){
        case "U":
            return [x,y+1];
        case "D":
            return [x,y-1];
        case "L":
            return [x-1,y];
        case "R":
            return [x+1,y];
    }
}
function solution(dirs) {
    let x = 0;   // 현재좌표 x,y
    let y = 0;
    const visited = new Set();  // 겹치는 좌표 처리 용이
    
    for(const dir of dirs){
        const [nx,ny] = updateLocation(x,y,dir);    // 다음 좌표 결정
        
        if(!isValidMap(nx,ny)) continue;
        
        // 같은 길에 2개의 방향이 존재할 수 있음, 전부 추가
        visited.add(`${x}${y}->${nx}${ny}`);
        visited.add(`${nx}${ny}->${x}${y}`);
        
        [x,y] = [nx,ny];    // 이동한 좌표로 현재좌표 업데이트
    }

    return visited.size / 2;
}
