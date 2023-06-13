#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int a[1'005];
int m;
int b[1'005];
vector<int> sum1;
vector<int> sum2;
long long ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>m;
    for(int i=0; i<m; i++) cin>>b[i];
    for(int i=0; i<n; i++){
        for(int j=i;j<n; j++){
            if(i==j) sum1.push_back(a[i]);
            else{
                int tmp=0;
                for(int p=i; p<=j;p++) tmp+=a[p];
                sum1.push_back(tmp);
            }
        }
    }
    // cout<<"sum1 size is : "<<sum1.size()<<'\n';
    for(int i=0; i<m; i++){
        for(int j=i;j<m; j++){
            if(i==j) sum2.push_back(b[i]);
            else{
                int tmp=0;
                for(int p=i; p<=j;p++) tmp+=b[p];
                sum2.push_back(tmp);
            }
        }
    }
    // cout<<"sum2 size is : "<<sum2.size()<<'\n';
    // for(auto c: sum1){
    //     cout<<c<<' ';
    // }
    // cout<<'\n';

    // for(auto c: sum2){
    //     cout<<c<<' ';
    // }
    // cout<<'\n';
    sort(sum2.begin(),sum2.end());
    for(auto c: sum1){
        auto up=upper_bound(sum2.begin(),sum2.end(),t-c);
        auto lb=lower_bound(sum2.begin(),sum2.end(),t-c);
        int cnt=up-lb;
        ans+=cnt;
    }
    cout<<ans;
}
//건너뛰면 안된다. 건너뛰어서 원소들끼리 골라내서 합치는게 아니라 
//그냥 쭉 일렬로 어디서부터 어디까지 구멍 없이 다 합쳐야 한다. 
//2중 for문으로 a의 원소들을 합친 경우의 수들중에서, 투포인터로 b의 배열들의
//합을 탐색하면,안된다. 투포인터는 정렬이 되어있어야지. 
//그냥 이중for문 하고, 그리고 이분탐색으로 해야겠다. 


