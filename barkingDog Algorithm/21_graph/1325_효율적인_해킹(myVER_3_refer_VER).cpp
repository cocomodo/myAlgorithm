#include <bits/stdc++.h>
using namespace std;

int mx;
int score[10'005];
vector<int> adj[10'005];
bool vis[10'005];

void dfs(int st){
    vis[st]=1;
    score[st]++;
    mx=max(mx,score[st]);
    for(int nxt:adj[st]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    // fill(score,score+10'005,0);
    for(int i=1; i<=n; i++){
        fill(vis,vis+10'005,0);
        dfs(i);
    }
    for(int i=1; i<=n; i++)
        if(score[i]==mx) cout<<i<<' ';
}