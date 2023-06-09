#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if(a==0) return b;
    return gcd(b%a,a);
}

long long lcm(long long a, long long b){
    return a/gcd(a,b)*b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long a, b;
        cin>>a>>b;
        cout<<lcm(a,b)<<'\n';
    }
}
