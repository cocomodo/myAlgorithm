#include <bits/stdc++.h>
using namespace std;

int a[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    int prev=a[n-1];
    int ans=0;
    for(int i=n-2;i>=0;i--){
        if(a[i]>=prev){
            ans+=a[i]-prev+1;
            a[i]=prev-1;
        }
        prev=a[i];
    }
    cout<<ans;
}