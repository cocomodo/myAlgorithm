#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<pair<int,int>> point;
    vector<pair<int,int>> mergePoint;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        point.push_back({x,y});
    }
    sort(point.begin(),point.end());
    
    int mstart=point[0].first;
    int mend=point[0].second;
    for(int i=1; i<n; i++){
        if(point[i].first<=mend&&point[i].second> mend) mend=point[i].second;
        if(point[i].first>mend) {
            mergePoint.push_back({mstart,mend});
            mstart=point[i].first;
            mend=point[i].second;
        }
    }
    mergePoint.push_back({mstart,mend});
    int ans=0;
    for(auto c: mergePoint)
        ans+=c.second-c.first;
    cout<<ans;
}   

// 1 2 3 4 5 6 7 8 9 10
// 1   3
//   2     5 
//     3   5 
//           6 7

// 1->5 까지의 길이 4;
// 6->7 까지의 길이 1;
// 4+1=5;