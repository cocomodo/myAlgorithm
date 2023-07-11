#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1'005];
string name[1'005];
unordered_map<string, int> id;
int indeg[1'005];
vector<int> ch[1'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>name[i];
    }
    sort(name+1,name+n+1);
    
    for(int i=1; i<=n; i++){
        id[name[i]]=i;
    }

    cin>>m;
    for(int i=1; i<=m; i++){
        string s1, s2;
        cin>>s1>>s2;
        adj[id[s2]].push_back(id[s1]);
        indeg[id[s1]]++;
    }
    for(int i=1; i<=n; i++){
        sort(adj[i].begin(),adj[i].end());
    }
    vector<int> an;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0) an.push_back(i);
    }
    
    for(int i=1; i<=n; i++){
        for(int x: adj[i]){
            if(indeg[x]-indeg[i]==1) ch[i].push_back(x); 
        }
    }

    cout<<an.size()<<'\n';
    for(auto c: an) cout<<name[c]<<' ';
    cout<<'\n';
    for(int i=1; i<=n; i++){
        cout<<name[i]<<' '<<ch[i].size()<<' ';
        for(auto x: ch[i]) cout<<name[x]<<' ';
        cout<<'\n';
    }
}