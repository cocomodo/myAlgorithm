#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32'005];
int indeg[32'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=1; i<=n; i++)
        if(indeg[i]==0) pq.push(i);
    
    while(!pq.empty()){
        int cur=pq.top(); pq.pop();
        cout<<cur<<' ';
        for(auto nxt: adj[cur]){
            indeg[nxt]--;
            if(indeg[nxt]==0) pq.push(nxt);
        }
    }
    
}