#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n==1) return 0;
    for(int i=2; i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int ans;
int m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m;
    while(m--){
        int a;
        cin>>a;
        ans+=isprime(a);
    }
    cout<<ans;
}