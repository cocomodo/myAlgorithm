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
    for(int i=0; i<n; i++){
        if(!binary_search(b,b+m,a[i])){
            nums.push_back(a[i]);
        }
    }
    cout<<nums.size()<<'\n';
    for(auto c: nums) cout<<c<<' ';

}