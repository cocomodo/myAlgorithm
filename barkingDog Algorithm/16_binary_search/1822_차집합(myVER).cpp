// (2 5 11 ((7)) 9 4)
// 이런 경우 출력 
// 3
// 2 5 11

//b에서 a의 원소들을 이분탐색해서 0이 나오면 출력, 1이 나오면 안출력

#include <bits/stdc++.h>
using namespace std;

int n, m;//500'000;
int a[500'005];
int b[500'005];
vector<int> nums;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int cnt=0;
    for(int i=0; i<n; i++){
        if(!binary_search(b,b+m,a[i])){
            cnt++;
            nums.push_back(a[i]);
        }
    }
    if(cnt!=0){
        cout<<cnt<<'\n';
        for(auto c: nums) cout<<c<<' ';
    }else cout<<cnt;

}