#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[100002];
int score[100002];
vector<int> child[100002];

void dfs(int cur) {
  if(p[cur] != -1)
    score[cur] += score[p[cur]];
  for(int nxt : child[cur])
    dfs(nxt);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> p[i];
    if(p[i] == -1) continue;
    child[p[i]].push_back(i);
  }
  while(m--) {
    int i, w;
    cin >> i >> w;
    score[i] += w; /*이곳을 보니까 아무래도 칭찬을 한 직속 선배가 또 칭찬을 할 수
    있는 경우가 있는 형태의 문제로 보여진다*/
  }
  dfs(1);
  for(int i = 1; i <= n; i++) cout << score[i] << ' ';
}

/*
매번 칭찬을 아래로 뿌리면 O(nm)이지만 칭찬을
모아두었다가 마지막에 한번에 전파하면 O(n+m)에 해결 가능
*/