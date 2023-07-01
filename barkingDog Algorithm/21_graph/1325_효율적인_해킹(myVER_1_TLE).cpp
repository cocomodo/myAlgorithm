#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<int> adj[10'005];
int dist[10'005]; // 엄밀히 dist는 아니지만 dist로 두고 풀어보자.
int score[10'005];

int dfs(int st){
    fill(dist,dist+1+n,-1);
    stack<int> q;
    q.push(st);
    while(!q.empty()){
        int cur=q.top(); q.pop();
        for(auto nxt: adj[cur]){
            if(dist[nxt]!=-1) continue;
            dist[st]++;
            q.push(nxt);
        }
    }
    int mx_ele=*max_element(dist+1,dist+1+n);
    return mx_ele;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        cin>>v>>u;
        adj[u].push_back(v);
    }   

    for(int i=1; i<=n; i++)
        score[i]=dfs(i);
    
    int mx_mx_ele=*max_element(score+1,score+n+1);
    for(int i=1; i<=n; i++){
        if(score[i]==mx_mx_ele) cout<<i<<' ';
    }
}