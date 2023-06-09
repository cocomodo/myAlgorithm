#include <bits/stdc++.h>
using namespace std;

int func(int n) {
    int i=1;
    int sum=0;
    while(n>i){
        sum+=i*i;
        n-=i;
        i++;
    }
    return sum+i*n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin>>a>> b;
    cout<<func(b)-func(a-1);
}