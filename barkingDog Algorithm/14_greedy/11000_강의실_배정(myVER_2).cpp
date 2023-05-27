#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> events;
    for(int i=0; i<n; i++){
        int s,t;
        cin>>s>>t;
        events.push_back({s,1});
        events.push_back({t,-1});
    }
    sort(events.begin(),events.end());
    int maxcnt=0;
    int curtime=events[0].first;
    int curcnt=0;
    int idx=0;
    while(true){
        while(idx<2*n&&events[idx].first==curtime){
            curcnt+=events[idx].second;
            idx++;
        }
        maxcnt=max(maxcnt,curcnt);
        if(idx==2*n) break;
        curtime=events[idx].first;
    }
    cout<<maxcnt;
}