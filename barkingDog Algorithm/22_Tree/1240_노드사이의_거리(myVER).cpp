#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, u, v, d; //이때 d는 각각의 거리값
    cin>>n>>m;
    for(int i=0; i<n-1; i++){
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    
    /*bfs를 돌면서 각각의 노드들에 도달할때에 거리들을 추가하면서 쌓아나가고,
    다시 다음 노드들 까지도 연산하면서 거리들을 쌓아나가고, 반복하다가
    cur==v가 되면 그때까지 중첩한 거리를 출력하면서 break;를 걸면 된다.
    */
    while(m--){ 
        cin>>u>>v;
        queue<pair<int,int>> q;
        vector<bool> vis(n+1);
        q.push({u,0});
        vis[u]=true;
        while(!q.empty()){/*queue가 빌때까지 쭉 탐색하기 때문에 계속해서 
        다음 노드, 다음 노드로 나아가게 된다. 그래서 cur==v, 즉 현재 도착한 
        노드가 목표한 v 노드라면, 지금까지 누적된 dist를 출력하면 된다 */ 
            auto [cur,dist] =q.front();
            q.pop();
            if(cur==v){
                cout<<dist<<'\n';
                break;
            }
            for(auto [nxt,nxtDist]: adj[cur]){
                if(vis[nxt]) continue;
                vis[nxt]=true;
                q.push({nxt,dist+nxtDist});
            }
        }
    }
}