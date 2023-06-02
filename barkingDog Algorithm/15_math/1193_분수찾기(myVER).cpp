// 10번째 라고 해보자

// (1) (2 3) (4 5 6 ) (7 8 9 10) (11 12 13 14 15)
// (1) (1 2) (3 2 1)  (1 2 3 4 ) (5 4 3 2 1)
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    int i=1;
    while(n>i){
        n-=i;
        i++;
    }
    if(i%2==0){
        cout<<n<<'/'<<i+1-n;
    }else{
        cout<<i+1-n<<'/'<<n;
    }
}