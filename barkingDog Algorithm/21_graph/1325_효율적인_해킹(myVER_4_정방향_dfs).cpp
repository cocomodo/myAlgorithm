#include <bits/stdc++.h>
using namespace std;

int mx;
int n, m;
vector<int> adj[10'005];
int score[10'005];
bool vis[10'005];

int score_cur[10'005];

int dfs(int cur){
    vis[cur]=true;
    score[cur]++;
    for(auto nxt: adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
        score[cur]+=score[nxt];
    }
    mx=max(mx,score[cur]);
    return score[cur];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>v>>u;
        adj[u].push_back(v);
    }
    
    for(int i=1; i<=n; i++){
        fill(vis,vis+n+1,false);
        fill(score,score+n+1,0);
        score_cur[i]=dfs(i);
    }
    for(int i=1; i<=n; i++){
        if(score_cur[i]==mx) cout<<i<<' ';
    }
}