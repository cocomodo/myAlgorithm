//0.5s 256MB
#include <bits/stdc++.h>
using namespace std;

int n;
int a[2005];
int m;
int d[2005][2005];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n;i++)
        cin>>a[i];

    for(int i=1; i<=n; i++){
        d[i][i]=1;
        if(a[i-1]==a[i]) d[i-1][i]=1;
    }
    for(int gap=2; gap<n; gap++){
        for(int i=1; i<=n-gap; i++){
            int s=i, e=i+gap;
            if(a[s]==a[e]&&d[s+1][e-1]) d[s][e]=1;
        }
    }


    cin>>m;
    while(m--){
        int s,e;
        cin>>s>>e;
        cout<<d[s][e]<<'\n';
    }
    return 0;
}