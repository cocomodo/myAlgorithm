#include <bits/stdc++.h>
using namespace std;

int n,m, u, v;

vector<int> adj[1005];
bool vis[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int cnt=0;

    //그래프 입력
    for(int i=1; i<=m; i++){//이때 n은 정점의 갯수인데, 간선의 개수만큼을 받는연산을 진행시켜야 한다. 
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //BFS
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        cnt++;
        queue<int> q; 
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int cur=q.front(); q.pop();
            for(auto nxt: adj[cur]){
                if(vis[nxt]) continue; //이게 없으면 무한루프를 돈다. 왜 이곳에 이 코드가 있어야 하는지 논리적으로 이해를 해야한다. 
                q.push(nxt);
                vis[nxt]=true;
            }
            // cout<<"check"<<'\n';
        }
    }
    cout<<cnt;
}