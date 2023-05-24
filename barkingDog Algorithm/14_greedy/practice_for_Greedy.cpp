#include <bits/stdc++.h>
using namespace std;

int n, ans;
int p[1005];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>p[i];
    sort(p,p+n);
    for(int i=0; i<n; i++)
        ans+=p[i]*(n-i);
    cout<<ans;
}