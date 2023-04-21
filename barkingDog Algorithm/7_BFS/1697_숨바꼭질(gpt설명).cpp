#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dist[100002]; // 각 위치까지의 최소 이동 횟수를 저장하는 배열
int n, k; // 시작 위치와 도착 위치

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> k; // 시작 위치와 도착 위치 입력
  
  fill(dist, dist+100001, -1); // dist 배열을 -1로 초기화
  dist[n] = 0; // 시작 위치의 최소 이동 횟수는 0으로 설정
  
  queue<int> Q; // BFS를 위한 큐 생성
  Q.push(n); // 시작 위치를 큐에 넣음
  
  while(dist[k] == -1){ // 목표 위치의 최소 이동 횟수를 찾을 때까지 반복
    int cur = Q.front(); Q.pop(); // 큐에서 현재 위치를 꺼냄
    for(int nxt : {cur-1, cur+1, 2*cur}){ // 현재 위치에서 이동 가능한 3가지 경우를 고려
      if(nxt < 0 || nxt > 100000) continue; // 범위를 벗어나면 스킵
      if(dist[nxt] != -1) continue; // 이미 방문한 위치인 경우 스킵
      dist[nxt] = dist[cur]+1; // 최소 이동 횟수를 갱신하여 dist 배열에 저장
      Q.push(nxt); // 다음 위치를 큐에 넣음
    }        
  }
  
  cout << dist[k]; // 도착 위치의 최소 이동 횟수 출력

  return 0;
}