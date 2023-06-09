#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int a[1'000'005];
int ans;

int solve(int x){
    long long cur=0; //처음에 int cur=0; 으로 선언했다가 int overflow 로 틀렸다.
    //그 후 이 값만 long long cur=0; 으로 변경후 통과. ㄴ
    for(int i=0; i<n; i++){
        if(a[i]>x) cur+=a[i]-x;
    }
    return cur>=m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    int st=0;
    int en=*max_element(a,a+n);
    while(st<=en){
        int mid=(st+en)/2;
        if(solve(mid)){
            st=mid+1;
            ans=max(ans,mid);
        }
        else
            en=mid-1;
    }
    cout<<ans;
}