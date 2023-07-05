#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[55];
bool vis[55];

void dfs(int cur){
    vis[cur]=true;
    for(auto nxt: adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt]=true;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    int root=0;
    for(int i=0; i<n; i++){
        int u;
        cin>>u;
        if(u==-1) root=i;
        else{
            adj[i].push_back(u);
            adj[u].push_back(i);
        }
    }
    int del;
    cin>>del;
    vis[del]=true;

    

}