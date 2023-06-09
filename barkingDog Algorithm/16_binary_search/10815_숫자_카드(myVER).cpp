#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    cin>>m;
    while(m--){
        int t;
        cin>>t;
        cout<<binary_search(a,a+n,t)<<' '; 
    }   
}