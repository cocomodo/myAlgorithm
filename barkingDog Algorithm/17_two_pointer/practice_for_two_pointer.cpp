/*
5
1 2 3 1 2 의 예제 입력에 대한 경우의 수를 나열해보면, 

1 
1 2
1 2 3 //en++ 할때마다 경우의 수를 ans++ 한다.
2 //체크한 배열의 원소를 만나면 st++ 하고 en=st로 옮긴다. st++ 시에도 ans++ 한다.
2 3
2 3 1
3
3 1
3 1 2
1
1 2
2
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int chk[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        int p; 
        cin>>p;

    }
}