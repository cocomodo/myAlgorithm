#include <bits/stdc++.h>
using namespace std;

long long a[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    a[n]=(1ll<<62)+1;//아래 for문의 판단 과정이, 값에 대한 비교를 하기 때문에 이 값에는 아무런 값을 넣으면 안되고, (1ll<62)+1;을 넣어주어야 한다. 0을 넣었다가 틀렸다. 
    int cnt=1;
    long long mxval=0;
    int mxcnt=0;
    for(int i=1; i<=n; i++){
        if(a[i-1]==a[i]) cnt++; //이번 항이 전 항과 같아서 cnt를 증가시킬때. 이 경우 맨 마지막에 이 연산이 진행되면 판단 절차는 진행되지 않는다. 그래서 for문 밖에 맨 마지막 원소에서의 판단을 진행시켜주어야 한다. 
        else{//값이 딱 바뀌어서 전 원소까지의 값과 cnt로 판단할때
            if(cnt>mxcnt){
                mxcnt=cnt;
                mxval=a[i-1];
            }
            cnt=1; //수가 딱 바뀌었는데, 그 전까지의 cnt가 mxcnt보다 크지 않을때. 
        }
    }
    // if(cnt>mxcnt) mxval=a[n-1];
    cout<<mxval;
}