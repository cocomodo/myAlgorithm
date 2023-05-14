#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int ans=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=n;i>=1;i--){
        if(a[i]>k) continue;
        ans+=k/a[i];
        k%=a[i];
    }
    cout<<ans;
}