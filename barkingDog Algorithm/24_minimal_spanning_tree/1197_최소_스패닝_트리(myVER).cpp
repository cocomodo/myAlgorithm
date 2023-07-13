#include <bits/stdc++.h>
using namespace std;

int n, m;
//{정점, 비용} 순서 주의.
vector<pair<int,int>> adj[10'005];
int chk[10'005];
int cnt=0;
priority_queue<tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    while(m--){
        int u,v,d;
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    chk[1]=1;
    long long ans=0;
    for(auto nxt: adj[1])
        pq.push({nxt.second,1,nxt.first});
    while(cnt<n-1){
        int cost,a,b;
        tie(cost,a,b)=pq.top(); pq.pop();
        if(chk[b]) continue;
        ans+=cost;
        chk[b]=1;
        cnt++;
        for(auto nxt: adj[b]){
            if(!chk[nxt.first]) //이때 nxt.first는 v, second는 d.
                pq.push({nxt.second,b,nxt.first});
        }
    }
    cout<<ans;
}