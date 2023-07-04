#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> hv[105],li[105];
bool vis[105];

bool solve(int st, vector<int> (&adj)[]){
    fill( vis, vis+n+1, 0);
    queue<int> q;

    vis[st]=1;
    q.push(st);

    int cnt=0;
    while(!q.empty()){
        int cur= q.front(); q.pop();
        for(int nxt: adj[cur]){
            if(vis[nxt]) continue;
            vis[nxt]=1;
            q.push(nxt);
            cnt++;
        }
    }
    return cnt>=(n+1)/2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        hv[u].push_back(v);
        li[v].push_back(u);
    }

    int ans=0;
    for(int i=1; i<=n; i++)
        ans+=(solve(i,hv) || solve(i,li));
    
    cout<<ans;
}