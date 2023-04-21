typedef long long ll;

ll func1(ll a, ll b, ll m){
    ll val=1;
    while(b--) val=val*a%m;
    return val;
}