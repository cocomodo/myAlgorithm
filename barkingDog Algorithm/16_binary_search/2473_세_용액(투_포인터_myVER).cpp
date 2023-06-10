#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[5005];
int answer[3];
int n;

int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>> a[i];
    sort(a,a+n);
    ll ans=3e9;
    for(int st=0; st<n-2; st++){
        int mid=st+1;
        int en=n-1;
        while(mid<en){
            ll cur=a[st]+a[mid]+a[en];
            if(abs(ans)>abs(cur)){
                ans=cur;
                answer[0]=a[st];
                answer[1]=a[mid];
                answer[2]=a[en];
            }
            if(cur>=0) en--;
            else mid++;
        }
    }
    sort(ans,ans+3);
    for(int i=0; i<n; i++) cout<<answer[i]<<' ';
}