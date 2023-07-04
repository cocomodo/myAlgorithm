/*
방문 표시가 남아있는데, 자신의 부모가 아니라면, 이건 사이클이 존재한다는 얘기이다. 
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[505];
bool vis[505];
int p[505];
int cnt;
void bfs(){
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i]=true;
        cnt++;
        while(!q.empty()){
            int cur=q.front(); q.pop();
            for(auto nxt: adj[cur]){
                if(p[cur]==nxt) continue;
                if(nxt!=p[cur] && vis[nxt]==true) {
                    cnt--; 
                    return;
                } 
                q.push(nxt);
                p[nxt]=cur;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    while(m--){
        int u, v; 
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt=0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i]=true;
        cnt++;
        while(!q.empty()){
            int cur=q.front(); q.pop();
            for(auto nxt: adj[cur]){
                if(p[cur]==nxt) continue;
                if(nxt!=p[cur] && vis[nxt]==true) {
                    cnt--; 
                    break;
                } 
                q.push(nxt);
                p[nxt]=cur;
            }
        }
    }
    cout<<cnt;
}