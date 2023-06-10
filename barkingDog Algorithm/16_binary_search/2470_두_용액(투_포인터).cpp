#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    int ans=2*1e9+1;

    int st=1;
    int en=n;
    int ans1,ans2;
    while(st<en){
        int cur=arr[st]+arr[en];
        int num=abs(cur);
        if(ans>num){
            ans=num;
            ans1=arr[st];
            ans2=arr[en];
        }
        if(cur>0) en--;
        else st++;
    }
    cout<<ans1<<' '<<ans2;
}
/*
이 풀이의 경우 예제 입력2 이
4 
-100 -2 -1 103
인 경우, -100 103 이 출력되는데, 예제 출력 2의 값인 -2 -1 과 같이,
<특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 그 중 아무것이나 하나를 출력한다.> 라는 사항에 부합하는 경우이다. 
-2 + -1 =-3, -100 + 103 = 3 으로 둘의 절대값은 같아서 특성값이 0에 가까움이 똑같다.
*/
