#include <bits/stdc++.h>
using namespace std;

int tc, n, m;
vector<int> adj[20'005];
int gr[20'005];

bool solve(){
    fill(gr,gr+n+1,-1);

    for(int i=1; i<=n; i++){
        if(gr[i]!=-1) continue;

        queue<int> q;
        gr[i]=0;
        q.push(i);
        
        while(!q.empty()){
            int cur=q.front(); q.pop();
            for(auto nxt: adj[cur]){
                if(gr[nxt]!=-1){
                    if(gr[nxt]==gr[cur]) return false;
                    else continue;
                }
                gr[nxt]=(gr[cur]+1)%2;
                q.push(nxt);
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            adj[i].clear();
        }
        while(m--){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}