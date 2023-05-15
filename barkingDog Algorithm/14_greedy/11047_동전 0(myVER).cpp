#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    
    int ans=0;
    int q=0;
    int r=0;
    for(int i=n; i>0;i--){
        if(a[i]>k) continue;
        if(k%a[i]==0) {
            ans+=k/a[i];
            cout<<ans;
            return 0;
        }
        q=k/a[i];
        r=k%a[i];
        
        ans+=q;
        // k-=q*a[i];
        k=r;

    }
}