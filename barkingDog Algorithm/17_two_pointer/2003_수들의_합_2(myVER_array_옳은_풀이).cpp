#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    int ans=0,st=0,en=0,tot=a[0];
    //a[n]==0; 전역변수로 선언했기 때문에 초기화가 0으로 되어있어서 불필요한 코드.
    while(1){
        if(tot==m) ans++;
        if(tot<=m) tot+=a[++en];
        if(tot>m) tot-=a[st++];
        if(en==n) break;/*vector코드 형태와 다른부분은 en이 의미하는 바가 
        vector풀이는 갯수, array 풀이는 인덱스 라는 상황이라는 것이라고 생각된다. 
        이 경우 array 풀이에서 올바른 경우를 출력하려면, en=0부터 시작을 하거나
        혹은 en=1로 시작을 한뒤에 맨 마지막 while문 탈출 부분을 vector처럼 갯수
        형태로 판단하는게 아니라 인덱스값으로 고려해서 판단해주어야 올바른 코드가 된다고
        보여진다. */
        //그래서 en=0으로 시작해서 en==n으로 판단하거나, 
        //en=1로 시작해서 en==n+1로 해야 옳바른 arrary 를 이용한 풀이가 될것이다. 
    }
    cout<<ans;
}
/* 
en=1 tot=a[0] en==n+1로 판단
en=0 tot=0 tot+=a[++en] en==n로 판단*/