#include <bits/stdc++.h>
using namespace std;

int n, u, v;
vector<int> adj[55];
int dist[55];
int score[55];

int bfs(int st) {
    fill(dist,dist+55,-1);
    queue<int> q;
    dist[st]=0;
    q.push(st);
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto nxt: adj[cur]){
            if(dist[nxt]!=-1) continue; //방문해서 이미 과거에 도착했었다는 의미.
            dist[nxt]=dist[cur]+1;
            q.push(nxt);
        }
    }
    int val=*max_element(dist+1,dist+n+1);
    if(val==0) return 0x7fffffff;
    return val;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    
    while(true){
        cin>>u>>v;
        if(u==-1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        score[i]=bfs(i);
    }
    vector<int> cand;
    int mn_score=*min_element(score+1,score+n+1);
    for(int i=1; i<=n; i++){
        if(score[i]==mn_score)  cand.push_back(i);
    }
    cout<<mn_score<<' '<<cand.size()<<'\n';
    for(auto c: cand) cout<<c<<' ';
}