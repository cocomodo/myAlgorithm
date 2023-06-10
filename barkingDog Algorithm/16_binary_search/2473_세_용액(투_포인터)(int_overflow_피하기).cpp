#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[5005];
int ans1,ans2,ans3;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    ll ans=3e9+1;
    for(int st=0; st<n-2;st++){
        int mid=st+1;
        int en=n-1;
        while(mid<en){
            ll cur=a[st]+a[mid]+a[en];/*여기서 오른쪽 계산이, int a[5005]; 로
            선언한 상태에서 ll cur= a[st]+a[mid]+a[en]; 으로 작성하면, 
            오른쪽의 연산에서 int overflow가 발생한다. 아주아주 생각을 못해내다가
            뒤늦게 찾았다. 이걸 피하기 위해서는 int a[5005] 로 선언했으면,
            ll cur = (long long)(a[st]+a[mid]+a[en]); 형태로 계산하던지, 
            아니면 1ll을 곱해주어서 캐스팅 해주어야 한다. */
            if(abs(ans)>abs(cur)){
                ans=cur;
                ans1=a[st];
                ans2=a[mid];
                ans3=a[en];
            }
            if(cur>=0) en--;//if(cur>0) en--; 으로 작성해도 통과한다.
            //cur==0일때 break; 형태로 코드를 작성해도 된다.
            else mid++; 
            /*
            if(cur>0) en--;
            else if(cur<0) mid++;
            else break; // cur==0일때.
            형태로 작성해도 된다.
            */
        }
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3;
}
//int overflow 피하는 방법
/*첫번째: long logn a[5005];로 선언하고 ll cur=a[st]+a[mid]+a[en] 로 작성하기*/
/*두번째: int a[5005]; 로 선언하고 ll cur=(long long)(a[st]+a[mid]+a[en])로
작성하기 */
/*세번째: int a[5005]; 로 선언하고 ll cur=1ll*a[st]+a[mid]+a[en]; 로 작성하기*/

/*주의: int a[5005]; 로 선언하고 ll cur=(1ll)*(a[st]+a[mid]+a[en])로 작성하면
int overflow 발생한다. 이건 오히려 굉장히 주의해야할 코드 작성 방법인것 같다. */

/*아무래도 위의 경우들 중에서 가장 좋은 방법은 애초부터 연산의 결과가 int 범위를 넘어서는
 연산을 하는 경우는 그냥 long long a[5005]; 형태로 선언하고 코드를 작성하는게 가장
실수를 줄이면서 int overflow를 방지할 수 있는 방법으로 보여진다. 이런 식으로 
코드를 작성하도록 하자.*/
