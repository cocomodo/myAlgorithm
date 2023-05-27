#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;    
    for(int i=0; i<n; i++)
        cin>>a[i];
    while(m--){
        sort(a,a+n);
        int mnum=a[0]+a[1];
        a[0]=mnum;
        a[1]=mnum;
    }
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=a[i];
    cout<<sum;
}
/*
틀린 풀이
*/