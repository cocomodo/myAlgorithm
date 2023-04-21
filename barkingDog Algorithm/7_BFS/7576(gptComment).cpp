#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002]; // 토마토 상자의 상태를 저장하는 배열
int dist[1002][1002]; // 토마토의 익는 날짜를 저장하는 배열
int n, m; // 상자의 세로, 가로 크기
int dx[4] = {1,0,-1,0}; // 상하좌우 방향벡터
int dy[4] = {0,1,0,-1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> m >> n; // 가로, 세로 크기 입력
  
  queue<pair<int,int> > Q; // 익은 토마토의 좌표를 저장하는 큐
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j]; // 토마토의 상태 입력
      if(board[i][j] == 1) // 익은 토마토의 좌표를 큐에 넣음
        Q.push({i,j});
      if(board[i][j] == 0) // 아직 익지 않은 토마토는 익는 날짜를 -1로 초기화
        dist[i][j] = -1;
    }
  }

  while(!Q.empty()){ // BFS를 통한 토마토 익는 날짜 계산
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위를 벗어나면 스킵
      if(dist[nx][ny] >= 0) continue; // 이미 익은 토마토인 경우 스킵
      dist[nx][ny] = dist[cur.X][cur.Y]+1; // 토마토가 익는 날짜를 갱신
      Q.push({nx,ny});
    }
  }

  int ans = 0; // 모든 토마토가 익는 날짜 중 최댓값을 저장하는 변수
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(dist[i][j] == -1){ // 아직 익지 않은 토마토가 있는 경우
        cout << -1; // -1 출력 후 종료
        return 0;
      }
      ans = max(ans, dist[i][j]); // 모든 토마토의 익는 날짜 중 최댓값 갱신
    }
  }

  cout << ans; // 결과 출력

  return 0;
}