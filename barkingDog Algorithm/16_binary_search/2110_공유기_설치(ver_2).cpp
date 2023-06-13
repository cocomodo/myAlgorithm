#include <bits/stdc++.h>
using namespace std;

const int mx=200'000;
int n, c;
int house[mx];
bool possible(int dist){
    int cnt=1;
    int prev=house[0];
    //조건 충족하는지 확인
    for(int i=1; i<n; i++){
        if(house[i]-prev>=dist){
            cnt++;
            prev=house[i];
        }
    }
    //조건 충족
    if(cnt>=c)
        return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;
    for(int i=0; i<n; i++) cin>>house[i];
    sort(house,house+n);
    int low=1;
    int high=house[n-1]-house[0];
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(mid)){
            ans=max(ans,mid);
            low=mid+1;
        }
        else
            high=mid-1;
    }
    cout<<ans<<'\n';
}