#include <bits/stdc++.h>
using namespace std;

int n,s;
int a[100'005];
int ans=0x7fffffff;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n; i++) cin>>a[i];
    int en=0;
    int tot=a[0];
    for(int st=0; st<n;st++){
        while(en<n && tot<s) {
            en++;
            tot+=a[en];
        }
        if(en==n) break;
        ans=min(ans,en-st+1); 
        if(tot>=s){
            tot-=a[st];
            st++;
        }
    }
    cout<<ans;
}