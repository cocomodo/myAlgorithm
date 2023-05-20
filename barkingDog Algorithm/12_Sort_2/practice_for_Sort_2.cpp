#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100'005];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    a[n]=(1ll<<62)+1;
    sort(a,a+n);
    int cnt=1;
    long long mxval=-(1ll<<62)-1; //1을 long long 으로 형변환하지 않고 1<<62로 작성시 int overflow 발생
    int mxcnt=0;
    for(int i=1; i<=n; i++){
        if(a[i-1]==a[i]) cnt++;
        else{
            if(cnt>mxcnt){
                mxcnt=cnt;
                mxval=a[i-1];
            }
            cnt=1;
        }
    }
    //if(cnt>mxcnt) mxval=a[n-1]; //a[n]=(1ll<<62)+1;로 대입하고 n번째까지 확인하지 않고, 그냥 n-1까지만 시행하고, 가장 맨 마지막 원소일때를 이렇게 for문을 다 돌고 나서 맨 마지막에 마지막 원소에서 판단해주는 코드. 
    cout<<mxval;
}