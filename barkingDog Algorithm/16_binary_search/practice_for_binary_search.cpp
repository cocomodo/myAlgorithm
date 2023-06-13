#include <bits/stdc++.h>
using namespace std;

int n,c;
int a[200'005];
bool possible(int len){
    int cnt=1;
    int prev=a[0];
    for(int i=1; i<n;i++){
        if(a[i]-prev>=len){
            cnt++;
            prev=a[i];
        }
    }
    if(cnt>=c) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    int st=1;
    int en=a[n-1]-a[0];
    int ans=0;
    while(st<=en){//여기를 st<en으로 두면 예제에서 잘못된 값이 나오게 된다. 
        int mid=(st+en)/2; //mid 값은 st와 en의 가운데 위치하는 절반 거리
        if(possible(mid)){
            ans=max(ans,mid);
            st=mid+1;
        }else en=mid-1;
    }
    cout<<ans;
}