#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[20'005];
int v, e, st;
int d[20'005];
const int INF=0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e;
    cin>>st;
    
    while(e--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v}); 
    }
    fill(d,d+1+v,INF);

    priority_queue< pair<int,int>, 
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;
    
    d[st]=0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt: adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first) continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }
    for(int i=1; i<=v; i++){
        if(d[i]==INF) cout<<"INF\n";
        else cout<<d[i] <<'\n';
    }
}