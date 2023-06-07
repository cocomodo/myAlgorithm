#include <bits/stdc++.h>
using namespace std;

int n;
int a[500'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    int m;
    cin>>m;
    while(m--){
        int t;
        cin>>t;
        cout<<upper_bound(a,a+n,t)-lower_bound(a,a+n,t)<<' ';
    }
}