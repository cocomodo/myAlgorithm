#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int a[200'005];
int cnt[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];
    int en=0;
    cnt[a[en]]++;
    for(int st=0; st<n; st++){
        cout<<"||st|| is : "<<st<<'\n';
        while(en+1!=n && cnt[a[en+1]]<k){/*여기가 <k인지, <=k인지의 차이가 매우
        중요하다.*/
            en++;
            cnt[a[en]]++;/*위의 판단 기준 중 하나가 cnt[a[en+1]]<k이므로, 
            이 부분을 통해서 cnt[a[en]]==k인 경우가 나오게 될 수 있다. 
            그 경우에는 이제 딱 거기까지가 ans를 판단해야 하는 경우가 된다. */
            cout<<"<<en>> is : "<<en<<'\n';
        }
        ans=max(ans,en-st+1);
        cnt[a[st]]--;
    }
    cout<<ans;
}