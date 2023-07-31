#include <bits/stdc++.h>
using namespace std;

const long long INF=0x7f7f7f7f7f7f;
int n, m, k;
long long d[100'005];
vector<pair<long long , int>> adj[100'005];
priority_queue< pair<long long, int>,
                vector<pair< long long, int>>,
                greater<pair<long long, int>> > pq;

void solve(){
    
    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt: adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first) continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    fill(d+1,d+n+1,INF);

    while(m--){
        int u, v;
        long long w; 
        cin>>u>>v>>w;
        adj[v].push_back({w,u});
    }
    int ct;
    while(k--){
        cin>>ct;
        d[ct]=0;
        pq.push({d[ct],ct});
    }
    solve();
    int cidx=max_element(d+1,d+n+1)-d;
    cout<<cidx<<'\n'<<d[cidx];
}