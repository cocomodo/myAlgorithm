#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    int ans=0,st=0,en=1,tot=a[0];
    //a[n]==0; 전역변수로 선언했기 때문에 초기화가 0으로 되어있어서 불필요한 코드.
    while(1){
        if(tot==m) ans++;
        if(tot<=m) tot+=a[en++];
        if(tot>m) tot-=a[st++];
        if(en==n) break;
    }
    cout<<ans;
}

/*
이 풀이의 경우, boj 1644번 풀이의 방법을 vector 형태가 아닌 array 형태로 바꾸어서
제출해보았는데, 통과하지 못한 풀이. 이 이후에 vector로 다시 작성해서 통과하긴 했는데
현재 array 버전과 vector 버전에서의 차이가 어느 부분에서 발생해서 통과하지 못하는지에 대해서
찾아보아야 함.*/

/*예제의 입출력에 대해서는 정상적으로 동작하는데, 
아무래도 n==1일때, 혹은 n=10'000 일대 처럼 양 극단에서 예상과는
다른 동작을 하는게 아닌가 싶음. 
*/