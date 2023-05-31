#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+2;

int dp[MAX];
int stCnt, stNum;
int chainMaxLIS;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>stCnt;

    for(int i=0; i<stCnt;i++){
        cin>>stNum;
        dp[stNum]=dp[stNum-1]+1;
        chainMaxLIS=max(chainMaxLIS,dp[stNum]);
    }
    cout<<stCnt-chainMaxLIS;
}