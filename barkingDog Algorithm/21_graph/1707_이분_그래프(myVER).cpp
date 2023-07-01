#include <bits/stdc++.h>
using namespace std;

int tc;
int n, m;
vector<int> adj[20'005];
bool vis[20'005];
bool rb[20'005];

int dfs(int cur, int chk){
    vis[cur]=true;
    rb[cur]=chk;
    for(auto nxt: adj[cur]){
        if(vis[nxt]&&rb[cur]==rb[nxt]) {
            return -1;
        }
        if(vis[nxt]) continue;
        dfs(nxt,-chk);
    }
    return 1;
}
int posible;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        while(m--){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        for(int i=1; i<=n; i++){
            fill(vis,vis+n+1,0);
            posible=dfs(i,1);
            if(posible==-1){
                cout<<"NO"<<'\n';
                return 0;
            }
        }
        cout<<"YES"<<'\n';
    }
    return 0;
}