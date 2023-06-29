/*
bfs를 돌고, 거리가 상근이를 기준으로 2 까지인 사람을 초대한다는 얘기. 
그래서 거리가 2까지인 사람들의 수를 세면 된다
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int dist[505];

int n, m; 
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist,dist+505,-1);
    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto nxt: adj[cur]){
            if(dist[nxt]!=-1) continue;
            q.push(nxt);
            
            dist[nxt]=dist[cur]+1;
            if(dist[nxt]<=2) ans++;
        }
    }
    cout<<ans;
}