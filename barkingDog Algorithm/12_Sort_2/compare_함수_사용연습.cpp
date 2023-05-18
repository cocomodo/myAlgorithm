#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    cout<<"Comparing "<<a<<" and  "<<b<<'\n';
    return a>b;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, key;
    cin>>n;
    int a[1000];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n,compare);

    for(int i=0; i<n; i++){
        cout<<a[i]<<",";
    }
}