#include <bits/stdc++.h>
using namespace std;

int a[100'005];
int n;

int binarysearch(int target){
    int st=0;
    int en=n-1;
    while(st<=en){
        int mid=(st+en)/2;
        if(a[mid]<target)
          st=mid+1;
        else if(a[mid]>target)
          en=mid-1;
        else // a[mid] ==target
          return 1;
    }
    return 0; // 위의 과정을 반복하다가 return 1 이 안되고 st>en이 되면서 while문이 더이상 돌지 않을때 이 명령문에 도달하고 return 0을 하고 함수가 종료. 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n); //맨날 vector만 보다보니 생경하게 느껴지는데, 배열은 이런식으로 sort하면 된다
    int m;
    cin>>m;
    while(m--){
        int t;
        cin>>t;
        cout<<binarysearch(t)<<'\n';
    }
}