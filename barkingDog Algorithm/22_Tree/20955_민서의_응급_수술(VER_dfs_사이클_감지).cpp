#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100'005];
bool vis[100'005];
bool cycle[100'005];

int n, m, cnt=0;

void dfs(int cur, int prev){
    vis[cur]=true;
    for(auto nxt: adj[cur]){
        if(!vis[nxt]){
            dfs(nxt,cur);
        }
        else if(!cycle[nxt] && nxt!=prev){ /*다음 노드가 방문을 했던 노드인데
         다음 노드인 때를 기점으로 사이클 체크를 아직 안했고, 다음 노드가 
         부모 노드가 아니라면 이 경우 과거에 다른 위치에서 사이클 체크를 했다는 의미*/
            cnt+=1;
        }
    }
    cycle[cur]=true;
}

int main(){
    int ans=0;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i,0);
            ans+=1;
        }
    }
    cout<<ans-1+cnt;
}