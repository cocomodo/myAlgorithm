#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
long long ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];

    int max_val=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>=max_val){
            ans+=a[i]-max_val+1;
            max_val-=1;
        }
        else{
            max_val=a[i];
        }
    }
    cout<<ans;
}