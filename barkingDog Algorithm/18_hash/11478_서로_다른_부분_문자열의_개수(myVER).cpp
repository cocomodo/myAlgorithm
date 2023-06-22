#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    unordered_set<string> uset;
    // vector<string> test;
    cin>>s;
    int en=(int)s.size();
    for(int i=0; i<en;i++){
        for(int j=1; j<=en;j++){
            // test.push_back(s.substr(i,j));
            uset.insert(s.substr(i,j));
        }
    }
    cout<<uset.size()<<'\n';
}