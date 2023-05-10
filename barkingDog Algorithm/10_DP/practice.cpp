//3 10
//1
//2
//5
//첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 
//다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 
//작거나 같은 자연수이다.

#include <bits/stdc++.h>
using namespace std;

int n;
int k;
int a[105];
int d[10'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    d[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=a[i];j<=k;j++){
            d[j]+=d[j-a[i]];
        }
    }
    cout<<d[k];
}