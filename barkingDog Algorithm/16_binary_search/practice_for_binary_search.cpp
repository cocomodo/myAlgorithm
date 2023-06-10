#include <bits/stdc++.h>
using namespace std;

int n;
int a[10'005];
long long cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    for(int st=0; st<n-2;st++){
        int mid=st+1;
        int en=n-1;
        while(mid<en){
            int cur=a[st]+a[mid]+a[en];
            if(cur==0) {
                cnt++;
                // cout<<'('<<a[st]<<','<<a[mid]<<','<<a[en]<<')'<<'\n';
            }
            if(cur>0) en--;
            else mid++;
        }
    }
    cout<<cnt;
}
//10
//2 -5 2 3 -4 7 -4 0 1 -6
//-6 -5 -4 -4 0 1 2 2 3 7