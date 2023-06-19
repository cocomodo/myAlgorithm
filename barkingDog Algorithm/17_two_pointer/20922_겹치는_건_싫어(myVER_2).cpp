#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int cnt[100'005];
int a[200'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];

    int en=0;
    cnt[a[en]]++;
    for(int st=0; st<n; st++){
        /*en+1이 수열의 끝을 넘지 않거나, 
        a[en+1]의 등장 횟수를 추가해도 k를 넘지 않을 경우 en++을 해서 수열 길이 연장*/
        while(en+1!=n && cnt[a[en+1]]<k){
            en++;
            cnt[a[en]]++;
        }
        /*연장을 할 수 있으면 위의 코드에서 연장하고, 연장을 할 수 없으면 현재 상태에서, 
        현재 길이를 최장 길이와 비교*/
        ans=max(ans,en-st+1);
        //시작 인덱스 값을 올리기 전에 수열의 시작에 해당하는 수의 등장 횟수를 줄임.
        cnt[a[st]]--;
    }
    cout<<ans;
}