/*
내가 구한 방법은, 면접장에서 도시들 까지 가는 길을 구한 것이다. 
그런데 이건 단방향 문제로 주어졌기 떄문에, 가는 방향과 오는 방향의 길이가 다르다
그래서 이렇게 구하면 안되고, 모든 길에서부터 다익스트라를 돌려서, k개로 주어진 면접장까지의
거리를 구해서 둘을 비교해야 한다. 
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int,int>> adj[100'005];
int d[100'005];
const int INF = 0x3f3f3f3f;
int minArray[100'005];

int solve(int a,int b){
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;

    fill(d,d+1+n,INF);
    int st=a;
    d[st]=0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur= pq.top(); pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt: adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first) continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }
    return d[b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>n>>m>>k;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }

    fill(minArray,minArray+1+n,INF);//n보다 위에서 이렇게 초기화 시키면 정상 동작하지 않음!!!!!!
    for(int i=1; i<=k; i++){
        int p;
        cin>>p;
        for(int j=1; j<=n; j++){
            if(minArray[j]>solve(j,p)) {
               minArray[j]=solve(j,p);
            }
        }
    }
    int ansval=*max_element(minArray+1,minArray+n);
    for(int i=1; i<=n; i++){
        if(minArray[i]==ansval)
        {
            cout<<i<<'\n';
            cout<<ansval;
            return 0;
        } 
    }
}