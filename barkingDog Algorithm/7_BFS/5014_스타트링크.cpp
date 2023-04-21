#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
int dist[1000002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> f >> s >> g >> u >> d;
  fill(dist+1, dist+f+1, -1);
  
  queue<int> q;
  dist[s] = 0; // 현재 위치의 거리를 0으로 둠
  q.push(s); // s층에서 시작
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(auto nxt : {cur + u, cur - d}){
      if(nxt > f || nxt <= 0 || dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }

  if(dist[g] == -1) cout << "use the stairs";
  else cout << dist[g];
}

// 해당 코드는 스타트링크 문제를 해결하기 위한 코드입니다. 문제에서는 건물의 총 층수(f), 현재 위치(s), 도착해야 할 층(g), 엘리베이터로 올라가는 층수(u), 엘리베이터로 내려가는 층수(d)가 주어집니다.

// 이 코드는 bfs를 이용하여 현재 위치에서부터 엘리베이터를 이용해 이동할 수 있는 층수를 모두 탐색하면서, 도착해야 할 층(g)에 도달할 때까지의 거리를 구하는 문제입니다.

// 코드의 구현 방법은 다음과 같습니다.

// 입력 받기
// f, s, g, u, d를 입력 받습니다.
// dist 배열 초기화
// dist 배열은 해당 층에 처음 방문할 때까지의 거리를 나타내는 배열입니다. 이 배열을 -1로 초기화합니다.
// fill 함수를 이용하여 dist 배열의 1번 인덱스부터 f번 인덱스까지 -1로 초기화합니다.
// bfs 탐색
// 시작 지점(s)부터 bfs 탐색을 시작합니다.
// q라는 큐를 이용하여 bfs를 구현합니다.
// 현재 위치(cur)에서 엘리베이터를 이용해 이동할 수 있는 층(nxt)을 탐색합니다.
// nxt가 건물의 총 층수(f)보다 크거나, 0보다 작거나, 이미 방문한 적이 있는 층(dist[nxt] != -1)일 경우에는 탐색하지 않습니다.
// nxt가 방문한 적이 없을 경우, dist[nxt]를 dist[cur] + 1로 갱신하고, 큐에 nxt를 push합니다.
// 결과 출력
// dist[g]가 -1인 경우에는 도착해야 할 층(g)에 도달할 수 없는 경우이므로 "use the stairs"를 출력합니다.
// 그렇지 않은 경우에는 dist[g]에는 시작 위치(s)에서 도착해야 할 층(g)까지의 최단 거리가 저장되어 있으므로, dist[g]를 출력합니다.