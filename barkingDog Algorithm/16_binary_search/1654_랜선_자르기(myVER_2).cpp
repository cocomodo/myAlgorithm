#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans;
int k,n;
int a[10005];

bool solve(ll x){
    ll cur=0;
    for(int i=0; i<k;i++) cur+=a[i]/x;
    return cur>=n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>k>>n;

    int maxi=0;
    for(int i=0; i<k; i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    ll st=1;
    ll en=maxi;
    while(st<=en){
        ll mid=(st+en)/2;
        if(solve(mid)){
            /* 현재 mid로 나눈 값이 n보다 크거나 같다면,
            st를 움직여 길이가 더 긴 경우는 가능한지 검사*/
            st=mid+1;
            //n개를 만들 수 있을때, 답을 더 큰 값으로 계속 갱신
            ans=max(ans,mid);
        }
        else
            /*현재 mid로 나눈 값이 n보다 작다면, 
            right 움직여 길이가 더 짧은 경우는 가능한지 검사*/
            en=mid-1;
    }
    cout<<ans;
}