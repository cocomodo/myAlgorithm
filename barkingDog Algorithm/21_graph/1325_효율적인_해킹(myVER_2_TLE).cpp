#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<int> adj[10'005];
int dist[10'005]; // 엄밀히 dist는 아니지만 dist로 두고 풀어보자.
int score[10'005];
bool vis[10'005];//과정을 돌았는지 표시. 
int dp[10'005];

void dfs(int st){
    fill(dist,dist+1+n,-1);
    stack<int> q;
    q.push(st);
    while(!q.empty()){
        int cur=q.top(); q.pop();
        for(auto nxt: adj[cur]){
            if(dist[nxt]!=-1) continue;
            dist[st]++;
            q.push(nxt);
            dp[st]=dp[nxt]+1;
        }
    }
    vis[st]=true;
    score[st]=dist[st];
    // cout<<st<<" 's ans is : "<<dist[st]<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    fill(dist,dist+10'005,-1);
    while(m--){
        cin>>v>>u;
        adj[u].push_back(v);
    }   

    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i);
    }
    
    int mx_mx_ele=*max_element(score+1,score+n+1);
    for(int i=1; i<=n; i++){
        if(score[i]==mx_mx_ele) cout<<i<<' ';
    }
}