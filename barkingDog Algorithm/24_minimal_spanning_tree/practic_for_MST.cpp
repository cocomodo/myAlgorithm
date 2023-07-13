#include <bits/stdc++.h>
using namespace std;

int tc;
int n, m;
vector<int> adj[1'005];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        while(m--){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<--n<<'\n';
    }    
}