/*이 문제의 경우, 기본적으로 처음으로 제시되는 순서로 돌리고, 벡터를 두개 준비해서
돌리면 되지 않을가 싶다. 역방향으로도 돌리고.
처음 제시된 순서로 돌리면 bfs를 돌때 거리를 쌓고, 그 거리가 각각의 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj1[105];//자기보다 큰걸 알기 위해 두는 방향 그래프
vector<int> adj2[105];//자기보다 작은걸 알기 위해 두는 방향 그래프
bool vis[105];
int cnt1[105];
int cnt2[105];

void dfs(int st, int cnt[], vector<int> adj[]){
    // cnt[st]++;
    vis[st]=true;
    for(auto nxt: adj[st]){
        if(vis[nxt]) continue;
        cnt[nxt]++;
        dfs(nxt, cnt, adj);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        adj1[u].push_back(v); //자기보다 큰걸 알기 위한 기본형태
        adj2[v].push_back(u); //자기보다 작은걸 알기 위한 변형형태
    }
    for(int i=1;i<=n; i++){
        fill(vis,vis+n+1,false);
        dfs(i,cnt1,adj1);
    }
    for(int i=1; i<=n; i++){
        fill(vis,vis+n+1,false);
        dfs(i,cnt2,adj2);
    }
    int mid=(1+n)/2;
    
    // for(int i=1; i<=n; i++) cout<<cnt1[i]<<' ';
    // cout<<'\n';
    // for(int i=1; i<=n; i++) cout<<cnt2[i]<<' ';

    int ans=0;
    for(int i=1; i<=n; i++){
        if(cnt1[i]>=mid) ans++;
        if(cnt2[i]>=mid) ans++;
    }
    cout<<ans;
}