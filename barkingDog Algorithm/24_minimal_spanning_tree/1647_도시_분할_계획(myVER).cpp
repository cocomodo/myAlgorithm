
#include <bits/stdc++.h>
using namespace std;

int n , m;
vector<pair<int,int>> adj[100'005];
int chk[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int c, a, b;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    priority_queue< tuple<int,int,int>, 
                    vector<tuple<int,int,int>>, 
                    greater<tuple<int,int,int>>> pq;
    int p=0;
    chk[1]=true;
    for(auto ch: adj[1]){
        pq.push({ch.first, 1, ch.second});
    }

    int cnt=0, ans=0;
    while(cnt<n-1){
        int c, a, b;
        tie(c,a,b)=pq.top(); pq.pop();
        if(chk[b]) continue;
        chk[b]=true;
        cnt++;
        ans+=c;
        p=max(p,c);
        for(auto nxt: adj[b]){
            if(chk[nxt.second]) continue;
            pq.push({nxt.first, b, nxt.second});
        }
    }
    cout<<ans-p;
}