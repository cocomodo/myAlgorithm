// 3
// 2
// 1 2
// 1000
// 3
// 1 5 10
// 100
// 2
// 5 7
// 22

#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10'005];
int d[10'005];
int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    while(t--){    
        cin>>n;
        for(int i=1;i<=n; i++)
            cin>>a[i];
        cin>>k;
        d[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=a[i];j<=k;j++){
                d[j]+=d[j-a[i]];
            }
        }
        cout<<d[k]<<'\n';
        for(int i=1;i<=k;i++)
            d[i]=0;
    }
}