#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> worker;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string name;
    string state;
    while(n--){
        cin>>name>>state;
        if(state=="enter"){
            worker.insert(name);
        }
        if(state=="leave"){
            worker.erase(name);
        }
    }
    vector<string> ans;
    for(auto e : worker){
        string tmp;
        tmp=e;
        ans.push_back(e);
    }
    sort(ans.begin(),ans.end(),greater<string>());
    for(auto s:ans) cout<<s<<'\n';
}