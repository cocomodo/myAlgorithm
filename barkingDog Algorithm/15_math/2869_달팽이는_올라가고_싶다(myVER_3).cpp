#include <bits/stdc++.h>
using namespace std;

double a, b, v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>v;
    cout<<(int)ceil((v-a)/(a-b))+1<<'\n';
}