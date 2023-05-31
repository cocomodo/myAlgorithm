#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int a=2;
    while(true){
        if(n==1) break;
        if(n%a==0){
            cout<<a<<'\n';
            n/=a;
        }
        else a++;
    }
}