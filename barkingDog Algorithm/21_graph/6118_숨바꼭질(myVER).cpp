#include <bits/stdc++.h>
using namespace std;

vector<int> adj[20'005];
int n, m; 
int dist[20'005];
vector<int> cand;
int mx;

void bfs(int st){
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
    mx=*max_element(dist+1,dist+n+1);
    for(int i=1; i<=n; i++){
        if(dist[i]==mx) cand.push_back(i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(dist,dist+20'005,-1);
    bfs(1);
    cout<<cand[0]<<' '<<mx<<' '<<cand.size();
}