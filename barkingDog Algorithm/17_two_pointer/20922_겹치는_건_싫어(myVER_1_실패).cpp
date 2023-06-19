/*
같은 원소가 k개 이하로 들어있는, 
즉, 최대 k개까지만 담고 그걸 넘어서면 멈추라고?
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200'005];
int chk[100'005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];
    int st=0;
    int en=0;
    int ans=0;
    int mxans=0;
    while(en<n){
        chk[a[en]]++;
        if(chk[a[en]]>k){
            ans=(en-1)-st+1;
            mxans=max(mxans,ans);
            st=en;/*이런 식의 풀이를 하면 문제를 잘못 이해한 것이다.
            쭉 땡겨와서 새롭게 시작하는게 아니라, st를 땡겨오면서도 가능한
            경우가 있는지 파악하면서 mxans를 갱신해주어야 한다. */ 
            chk[a[en]]=1;
        }        
        en++;
    }
    ans=(en-1)-st+1;
    mxans=max(mxans,ans);
    cout<<mxans;
}