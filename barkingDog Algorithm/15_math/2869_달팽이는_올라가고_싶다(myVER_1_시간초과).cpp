#include <bits/stdc++.h>
using namespace std;

int a, b, v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>v;
    int total=0,day=0;
    while(v>total){
        total+=a;
        day++;
        if(v<=total) break;
        total-=b;
    }    
    cout<<day;
}