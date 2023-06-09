#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[1'000'005];
int ans;

int solve(int x){
    int cur=0;
    for(int i=0; i<n; i++) cur+=a[i]/x;
    return cur>=m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i=0; i<n;i++) cin>>a[i];
    int st=1;
    int en=1'000'000'000;//*max_element(a,a+n); 을 이용해서 원소들 중 
    //가장 끝값을 이용해도 된다. 
    while(st<=en){
        int mid=(st+en)/2;
        if(solve(mid)) {
            ans=max(ans,mid);
            st=mid+1;
        }else 
            en=mid-1;
    }
    cout<<ans;
}