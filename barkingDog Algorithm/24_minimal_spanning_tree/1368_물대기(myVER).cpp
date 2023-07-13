#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> adj[305];
int wf[305]; //well-fee 우물 비용. 스펠링 이거 맞는지는 모르겄다. 
//그룹에 포함되었는지 체크하는 배열.
bool chk[305];

priority_queue< tuple<int,int,int>,
                vector<tuple<int,int,int>>,
                greater<tuple<int,int,int>>> pq; //우선순위 큐. 최소힙

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++){
      cin>>wf[i];
        // cout<<wf[i]<<"  <=here!!!"<<'\n';
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int cost;
            cin>>cost;
            if(i==j) continue;
            adj[i].push_back({cost,j});
            // adj[j].push_back({cost,i}); 이중for문이기 때문에 이거 필요없다. 
        }
    }
    
    chk[1]=true;
    for(auto nxt: adj[1]){
        pq.push({nxt.first,1,nxt.second});
    }
    int ans=0;
    int cnt=0;
    while(cnt<n-1){
        int cost, a, b;
        tie(cost,a, b)=pq.top(); pq.pop();
        if(chk[b]) continue;
        chk[b]=1;
        cnt++;
        ans+=cost;
        for(auto nxt: adj[b]){
            if(chk[nxt.second]==false)
                pq.push({nxt.first,b,nxt.second});
        }
    }
    cout<<ans;

}