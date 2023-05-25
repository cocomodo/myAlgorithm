#include <bits/stdc++.h>
using namespace std;

int a[1'000'005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];
        int max_val=a[n-1];
        long long ans=0;
        for(int i=n-2;i>=0;i--){
            if(a[i]>max_val) max_val=a[i];//더 큰 값이 나오면, max_value가 바뀌고, 그 다음줄에서의 연산에서 max_value - a[i] 에서, 자기 자신을 빼면서 값이 0이 되므로, 마이너스 값이 나오지 않고, ans에 더해지는 값은 0이다. 
            ans+=max_val-a[i];
        }
        cout<<ans<<'\n';
    }
}