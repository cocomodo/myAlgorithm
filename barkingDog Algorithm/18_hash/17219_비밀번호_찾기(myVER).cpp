#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    unordered_map<string,string> site;
    for(int i=0; i<n; i++){
        string name,pass;
        cin>>name>>pass;
        site[name]=pass;
    }
    while(m--){
        string query;
        cin>>query;
        cout<<site[query]<<'\n';
    }
}