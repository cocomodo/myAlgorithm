#include <bits/stdc++.h>
using namespace std;
//15 28 19
int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e, s, m;
    cin>>e>>s>>m;
    e--,s--,m--;

    int i=e;
    while(i%28!=s) i+=15;

    int l=lcm(15,28);
    while(i%19!=m) i+=l;
    cout<<i+1;
}
/*
c++17부터 numeric 헤더에 lcm함수가 있다. c++17이면 바로 lcm 함수를 사용할 수 있다.
현재 내 맥 설정상 c++14여서 바로 lcm 함수를 사용하면 오류가 발생한다. 
*/