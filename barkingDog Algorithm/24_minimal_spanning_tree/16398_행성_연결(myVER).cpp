#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1'005];
bool chk[1'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int cost;
            cin>>cost;
            if(i==j) continue;
            adj[i].push_back({cost,j});
        }
    }
    
    priority_queue< tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>> pq;
    
    chk[1]=true;
    for(auto nxt: adj[1]){
        pq.push({nxt.first,1,nxt.second});//if(chk[nxt.second]!=true) 이 부분을 제외하였다. 처음에는 그냥 다 넣어주는구나.
    }
    long long ans=0;
    int cnt=0;
    while(cnt<n-1){
        int cost, a, b;
        tie(cost, a, b)=pq.top(); pq.pop();
        if(chk[b]) continue; //이게 핵심이었는데, 이걸 빼먹었어. 가장 처음에는 다 넣어주고 판단부를 이렇게 while문 안쪽에다가 넣어주어야 한다. 
        chk[b]=true;
        ans+=cost;
        cnt++;
        for(auto nxt: adj[b]){
            if(chk[nxt.second]) continue;
            pq.push({nxt.first,b,nxt.second});

        }
    }
    cout<<ans;

}