#include <bits/stdc++.h>
using namespace std;

long long dp[505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[0]=1;
    for(int i=1; i<=500;i++){
        dp[i]=dp[i-1]*i;
    }
    int n;
    cin>>n; 
    long long i=0;
    long long x=dp[n];
    while(x%10==0){
        x/=10;
        i++;
    }
    cout<<i;
}
/*
시간초과 풀이.
*/