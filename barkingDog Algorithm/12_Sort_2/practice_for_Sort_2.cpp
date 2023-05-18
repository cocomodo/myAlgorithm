#include <bits/stdc++.h>
using namespace std;


int n;
string s[55];

bool cmp(string& a, string& b){
    cout<<"Comparing "<<a<<" and "<<b<<'\n';
    int lena=a.size(),lenb=b.size();
    int suma=0,sumb=0;
    if(lena!=lenb) return lena<lenb;
    for(int i=0; i<lena; i++) {
        if(isdigit(a[i])) suma+=a[i]-'0';
    }
    for(int i=0; i<lenb;i++){
        if(isdigit(b[i])) sumb+=b[i]-'0';
    }
    if(suma!=sumb) return suma<sumb;
    return a<b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    for(int i=0; i<n; i++)
    cout<<s[i]<<'\n';
}