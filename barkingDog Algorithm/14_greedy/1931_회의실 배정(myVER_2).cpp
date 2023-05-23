#include <bits/stdc++.h>
using namespace std;

pair<int,int> s[100'005];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i].second>>s[i].first;
    }
    sort(s,s+n);
    int cnt=1;
    int now=s[0].first;
    for(int i=1; i<n; i++){
        if(now<=s[i].second) {//처음에 = 을 빼먹어서 들렸다. 몇몇 문제에서 등호 관계를 같이 고려해주지 않아서 틀리고 있다. 대소관계를 비교해야 하는경우 등호를 포함해도 되는지 안되는지에 대해서 확실하게 고민해보고 문제를 해결하도록 하자. 
            now=s[i].first;
            cnt++;
        }
    }
    cout<<cnt;
}