#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> events;
    for(int i=0; i<n; i++){
        int l,r;
        cin>>l>>r;
        events.push_back({l,1});
        events.push_back({r,-1});
    }
    sort(events.begin(),events.end());
    int cnt=0;
    int tot=0;
    int loc=-1e9;
    for(auto event: events){
        if(cnt>0) tot+=event.first-loc;
        cnt+=event.second;
        loc=event.first;
    }
    cout<<tot;
}