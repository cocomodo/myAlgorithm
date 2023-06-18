#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int a[30'001*2];
int chk[3'001];
int ans;
int mxans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d>>k>>c;
    chk[c]++;
    ans=1;
    mxans=1;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[n+i]=a[i];
    }

    for(int i=0; i<n*2;i++){ /* i 하나 가지고 i-k와 i 라는 인덱스를 모두 움직여서
    앞쪽에 i-k 로 시작 위치를 조정하고, i로 끝 위치를 조정하면서 상황을 컨트롤 할 수 있다*/
        if(i==n+k-1) break;/*2531: 회전 초밥 문제의 경우는 n=30'000까지라 
        이렇게 멈추어 주는 것 없이 그냥 n*2 까지 다 계산해도 문제가 없지만, 
        15961번 문제의 경우는 n=3'000'000 까지이기 때문에 이런식으로 뒷부분에
        불필요한 인덱스에 접근하면 바로 멈추어주어서 시간을 단축시켜야 할 것이다. */
        if(i>=k){
            chk[a[i-k]]--;
            if(chk[a[i-k]]==0) ans--;
        }
        if(chk[a[i]]==0){
            ans++;
            mxans=max(mxans,ans);
        }
        chk[a[i]]++;
    }
    cout<<mxans;
}