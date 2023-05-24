#include <bits/stdc++.h>
using namespace std;

int r[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin>>n;
    int mxval=0;
    for(int i=1;i<=n; i++){
        cin>>r[i];
    }
        

    sort(r+1,r+1+n);
    for(int i=1; i<=n; i++)
    {
        int avg=(n-i+1)*r[i];
        mxval=max(mxval,avg);
    }
    cout<<mxval;
}