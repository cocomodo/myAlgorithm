#include <bits/stdc++.h>
using namespace std;

string s[55];
bool cmp(const string& a, const string& b){
    int lena=a.size(),lenb=b.size();
    int suma=0,sumb=0;
    if(lena!=lenb) return lena<lenb;
    for(int i=0; i<a.size();i++){
        if(isdigit(a[i])) suma+=(a[i]-'0');
        if(isdigit(b[i])) sumb+=(b[i]-'0');
    }
    if(suma!=sumb) return suma<sumb;
    return a<b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>s[i];
    sort(s,s+n,cmp);
    for(int i=0; i<n; i++)
        cout<<s[i]<<'\n';

}