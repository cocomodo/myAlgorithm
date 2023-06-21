#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    unordered_map<string,string> m2t;
    unordered_map<string, vector<string>> t2m;
    while(n--){
        string tname;
        int tnum;
        cin>>tname>>tnum;
        while(tnum--){
            string name;
            cin>>name;
            m2t[name]=tname;
            t2m[tname].push_back(name);
        }
        sort(t2m[tname].begin(),t2m[tname].end());
    }
    while(m--){
        string query;
        int casenum;
        cin>>query>>casenum;
        if(casenum)
            cout<<m2t[query]<<'\n';
        else{
            for(auto c: t2m[query]) cout<<c<<'\n';
        }
    }
}