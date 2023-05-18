#include <bits/stdc++.h>
using namespace std;

int n;
string st;
// vector<string> v;
string s[55];

bool cmp(string& a, string& b){
    int lena=a.size(),lenb=b.size();
    int suma=0,sumb=0;
    if(lena!=lenb) return lena<lenb;

    for(int i=0; i<lena; i++){ //숫자만 더한다.
        if(isdigit(a[i])) suma+=a[i]-'0';
    }
    for(int i=0; i<lenb;i++){
        if(isdigit(b[i])) sumb+=(b[i]-'0');
    }
    if(suma!=sumb) return suma<sumb;
    return a<b; //사전순 부분.
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        // cin>>st;
        // v.push_back(st);
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    for(int i=0; i<n; i++)
        cout<<s[i]<<'\n';
}