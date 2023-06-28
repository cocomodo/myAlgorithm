#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int t;
    cin>>t;
    while(t--){
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int n;
        cin>>n;
        int p;
        for(int i=0; i<n; i++){
            cin>>p;
            pq.push(p);
        }
        ll ans=0;
        while((int)pq.size()>1){
            ll a=pq.top(); pq.pop();
            ll b=pq.top(); pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        // ans+=pq.top();
        cout<<ans<<'\n';
    }
}

/*
1'000'000   10'000
500'000     20'000
250'000     40'000
125'000     80'000
62'500      160'000
31'250      320'000
15'626      640'000
7'813       1'280'000
3'900       2'560'000
1'950       5'120'000
975         10'000'000
487         20'000'000
253         40'000'000
126         80'000'000
63          160'000'000
31          320'000'000
15          640'000'000
7          1'280'000'000
3          2'560'000'000
1          5'120'000'000 51억까지 갈 수 있다.   
*/ 