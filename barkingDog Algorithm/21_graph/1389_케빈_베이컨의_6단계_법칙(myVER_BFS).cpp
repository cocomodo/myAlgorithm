#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int dist[105];//각 vertex까지의 거리를 기록할 배열
int score[105];//각각의 거리의 합을 입력할 배열
int tot_dist;
int n,m;

int bfs(int st){
    tot_dist=0;
    fill(dist,dist+105,-1);
    queue<int> q;
    dist[st]=0;
    q.push(st);
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto nxt: adj[cur]){
            if(dist[nxt]!=-1) continue;
            dist[nxt]=dist[cur]+1;
            q.push(nxt);
        }
    }
    for(int i=1; i<=n; i++){
        tot_dist+=dist[i];
    }
    return tot_dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        int u,  v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++){
        score[i]=bfs(i);
    }
    int min_kevin=*min_element(score+1,score+1+n);
    for(int i=1; i<=n; i++){
        if(score[i]==min_kevin) {
            cout<<i;
            return 0;
        }
    }
}