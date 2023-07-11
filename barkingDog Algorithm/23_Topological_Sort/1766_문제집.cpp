#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[32'005];
int deg[32'005];
priority_queue<int,vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        deg[v]++;
    }

    for(int i=1; i<=n; i++)
        if(deg[i]==0)  pq.push(i);

    while(!pq.empty()){
        int cur=pq.top(); pq.pop();
        cout<<cur<<' '; //이미 pq에 넣을때 if(deg[i]==0) 일때 넣어줘서, 확인해줄 필요 없다.
        for(int nxt: adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0) pq.push(nxt);
        }
    }
}