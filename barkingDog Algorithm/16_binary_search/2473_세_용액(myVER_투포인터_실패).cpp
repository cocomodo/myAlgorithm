#include <bits/stdc++.h>
using namespace std;

int n;
int a[5'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    int st=0;
    int en=n-1;
    long long ans=3*1e9+1;
    int ans1=0 ,ans2=0 , ans3=0;
    while(st<en-1){
        long long num=3*1e9+1;
        long long cur=0;
        for(int mid=st+1; mid<=en-1;mid++){
            cur=a[st]+a[mid]+a[en];
            num=abs(cur);
            if(num<ans){
                ans=num;
                ans1=a[st];
                ans2=a[mid];
                ans3=a[en];
            }
        }
        if(cur>0) en--;/*이런식으롱 st와 en 사이의 mid를 for문으로 움직이면
        여기 if(cur>0) en--; 코드가 위의 for문이 다 돌고 난 다음인 mid=en-1의 위치가
        된 경우에만 실행된다. 그래서 이런 식의 풀이는 잘못된 풀이이다. 
        for문으로 st의 값을 변경하고, 각각에 대해서 while(mid<en)형태로 투 포인터를
        활용해서 문제를 해결해야 한다.*/
        else st++;
       
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3;
}
//-97 -6 -2 6 98
