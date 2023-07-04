#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
bool vis[505];
bool isTree;

int n, m, tc, trees;

void dfs(int cur, int prev){
    for(int nxt: adj[cur]){
        if(nxt==prev)//next가 부모(Prev)일 경우 건너뜀
            continue;
        if(vis[nxt]){ /* 트리일 경우 자식은 반드시 이전에 방문한 적이 없었어야 하고,
        이전에 방문을 했다면 현재 보고 있는 conneted component가 트리가 아님을 의미 */
            isTree = false;
            continue;
            
        }
        vis[nxt]=true;
        dfs(nxt,cur);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>n>>m;
        if(!n && !m) break;

        fill(vis,vis+n+1,0);
        for(int i=1; i<=n; i++)
            adj[i].clear();
        trees=0;

        while(m--){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1; i<=n; i++){
            if(vis[i]) continue;
            vis[i]=true;
            isTree=true;
            dfs(i,-1);
            trees+=isTree;
        }
        cout<<"Case "<<++tc<<": ";
        if(!trees)
            cout<<"No trees." <<'\n';
        else if(trees==1)
            cout<<"There is one tree."<<'\n';
        else
            cout<<"A forest of "<<trees<<" trees."<<'\n';
    }
}