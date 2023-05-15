#include <bits/stdc++.h>
using namespace std;

int a[1'000'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    for(auto c:a) cout<<c<<'\n';
}