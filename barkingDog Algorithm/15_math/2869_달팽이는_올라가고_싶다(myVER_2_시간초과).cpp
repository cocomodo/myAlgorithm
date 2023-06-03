#include <bits/stdc++.h>
using namespace std;

int a, b, v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>v;
    int k=0;
    while((a-b)*k+a<v){
        k++;
    }
    k++;    
    cout<<k;
}