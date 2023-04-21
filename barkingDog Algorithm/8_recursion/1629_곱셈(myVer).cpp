// a를 b번 곱한 수를 c로 나눈 나머지
// 이 곱해가는 과정에서 c로 나누고, 그 나머지들끼리 곱하면서 c로 나누면 되는거다. 
#include <bits/stdc++.h>
using namespace std;

int func(int a, int b, int c){
    if(b==1) 
        return a%c;
    return (a*func(a,b-1,c))%c; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int a, b, c;
    cin>>a>>b>>c;
    cout<<func(a,b,c);
    return 0;

}