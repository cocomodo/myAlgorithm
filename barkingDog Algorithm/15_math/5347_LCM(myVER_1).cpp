#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

long long lcm(int a, int b){
    return 1ll*a/gcd(a,b)*b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<lcm(a,b)<<'\n';
    }
}
