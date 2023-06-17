#include <bits/stdc++.h>
using namespace std;

int n, m;
// int a[10'005];
vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        v.push_back(t);
    }
    v.push_back(0);
    int ans=0,st=0,en=1,tot=v[0];
    //a[n]==0; 전역변수로 선언했기 때문에 초기화가 0으로 되어있어서 불필요한 코드.
    while(1){
        if(tot==m) ans++;
        if(tot<=m) tot+=v[en++];
        if(tot>m) tot-=v[st++];
        if(en==int(v.size())) break;
    }
    cout<<ans;
}

/*
이 버전의 경우는 처음에 array로 풀었다가 통과하지 못해서, vector로 버전을
바꾸어서 제출한 코드이다. 이 코드는 기존에 통과했었던 boj 1644: 소수의 연속합
문제의 풀이 로직을 그대로 가져와서 풀어본 형태인데, 처음에 배열 버전으로 바꾸었다가
통과하지 못해서 그대로 백터 형태로 변형해서 제출했을때 통과하였다. 
 */