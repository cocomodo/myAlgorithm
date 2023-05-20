#include <bits/stdc++.h>
using namespace std;
string st[20'005];
bool cmp(const string& a, const string& b){
    int lena=a.size(),lenb=b.size();
    if(lena!=lenb) return lena<lenb;
    return a<b;
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>st[i];
    sort(st,st+n,cmp);
    for(int i=0; i<n; i++){
        if(i==0||st[i-1]!=st[i]) cout<<st[i]<<'\n';
    }
}