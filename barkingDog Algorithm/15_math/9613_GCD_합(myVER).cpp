#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int a[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;

    while(t--){
        long long ans=0;
        cin>>n;
        for(int i=0; i<n; i++)
          cin>>a[i];
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n;j++){
                if(a[i]>a[j]) ans+=gcd(a[j],a[i]);
                else ans+=gcd(a[i],a[j]);
                
            }
        }
        cout<<ans<<'\n';
    }
}
/*
100개의 n이 주어지는 경우 경우의 수는 (100)C(2) 이고, 이때의 경우의 수는 99*50 = 4950 가지이고, 이 각각의 경우에 대해서 만약 1'000'000이면 값은 1'000'000* 4950이 된다. 그냥 계산의 편의를 위해 5'000으로 잡으면, 
5'000'000'000의 값이 나오고, 이 값은 50억으로 int의 범위를 넘는다. 
*/